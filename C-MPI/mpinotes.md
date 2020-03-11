# MPI Communication routines
Seperate processes do **not** share memory variables. 
They (processes) are using **copies** of any variable defined in the **MPI** program

As a result, these *parallel* executing processes cannot communicate with each other by
exchanging information in memory variables.

To work around this, processes may use an **MPI Communiation Routine**
Basic routines include
+ `MPI_send` - Send a message to another process
+ `MPI_Recv` - Receive a message from another process

## MPI_Send
`int MPI_Send(void *data_to_send, int send_count, MPI_Datatype send_type, int dest_ID, int tag, MPI_Comm comm);`

+ `data_to_send`: variable of a C type that corresponds to `send_type`
+ `send_count`: number of data elements to be sent (> 0)
+ `send_type`: data type of the data to be sent (**MPI** datatype handle)
+ `dest_id`: process ID of destination
+ `tag`: message tag
+ `comm`: communicator (**MPI** handle)

When `MPI_Send()` is called from a process, the process is blocked until the data transfer has taken place and the `data_to_send` variable can be safely reused.


## MPI_Recv
`int MPI_Recv(void *received_data, int receive_count, MPI_Datatype receive_type, int sender_ID, int tag, MPI_Comm comm, MPI_Status *status);`

+ `received_data`: variable of a C type that corresponds to the `receive_type` supplied below
+ `receive_count`: number of data elements expected
+ `receive_type`: datatype of the data to be received (**MPI** datatype handle)
+ `sender_ID`: process ID of the sending process
+ `tag`: message tag (int)
+ `comm`: communicator (handle)
+ `status`: status struct (MPI_Status)

To accomadate for messages of uknown length or with various tag values:
+ `receive_count = MPI_ANY_SOURCE
+ `sender_ID = MPI_ANY_TAG`

Actually received information can be retrieved as with

```C
	count MPI_Get_count(&status, MPI_FLOAT, &true_received_count);
	received_source = status.MPI_SOURCE;
	received_tag = status.MPI_TAG;
```

When `MPI_Recv()` is called from a process, the process is blocked until the data transfer is
complete and the `received_data` variable is available for use

## MPI Datatype Handles
| MPI Datatype Handle | C Datatype    |
|---------------------|:-------------:|
| MPI_INT	      | int	      |
| MPI_SHORT           | short         |
| MPI_LONG            | long          |
| MPI_FLOAT           | float         |
| MPI_DOUBLE          | double        |
| MPI_CHAR            | char          |
| MPI_BYTE            | unsigned char |


## Common Pattern of Process Interaction
Among parallel processes, the **master** process allocates work to a set of **slave** processes
The **master** process then collects the results from the **slaves** to create a final result

The **Master** process will execute:
```C
/* distribute portions of array1 to slaves. */

   for(an_id = 1; an_id < num_procs; an_id++) { 

      start_row = an_id*num_rows_per_process;
      
      ierr = MPI_Send( &num_rows_to_send, 1, MPI_INT,
            an_id, send_data_tag, MPI_COMM_WORLD);

      ierr = MPI_Send( &array1[start_row], num_rows_per_process,
            MPI_FLOAT, an_id, send_data_tag, MPI_COMM_WORLD);
   }

   /* and, then collect the results from the slave processes,
    * here in a variable called array2, and do something with them. */

   for(an_id = 1 an_id < num_procs; an_id++) {

      ierr = MPI_Recv( &array2, num_rows_returned, MPI_FLOAT,
            MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
      
      /* do something with array2 here */

   }

   /* and then print out some final result using the
    * information collected from the slaves. */
```

+ **Master** process sends portions of `array1` to each **slave**
+ **Master** then receives a response from each **slave**
	+ Returned information is put in  `array2`
	+ However, array2 will be overwritten for every new message
	+ Save the results received in another variable
		+ So that previously received data persists
+ Receive information from any process using `MPI_ANY_SOURCE`
	+ To determine from which process information is received
		+ `status.MPI_SOURCE`

The **Slave** processes will execute:
```C
/* Receive an array segment, here called array2 */.  

   ierr = MPI_Recv( &num_rows_to_receive, 1 , MPI_INT,
         root_process, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

   ierr = MPI_Recv( &array2, num_rows_to_receive, MPI_FLOAT, 
         root_process, MPI_ANY_TAG, MPI_COMM_WORLD, &status);  

   /* Do something with array2 here, placing the result in array3,
    * and send array3 to the root process. */

   ierr = MPI_Send( &array3, num_rows_to_return, MPI_FLOAT,
         root_process, return_data_tag, MPI_COMM_WORLD);
```

+ Many **slave** processes could be running at the same time
+ Each **slave** process receives data in `array2` from the **master**
	+ However, the **slave** creates a local and private copy of that data
	  to work on
+ Each **slave** constructs its own copy of `array3`

