#include <stdio.h>
#include <stdlib.h>

//Linked lists take away the limitation of resizing and shifting arrays
//Data in a linked list does not need to be stored in a contiguous manner

//Node
typedef struct node_t {
	int data; //Any data type is fine, even another struct
	struct node *next;//Points to next node in the list
} node_t;

//Head, the starting point for each list
//Head will always point to the very first node in the linked list
node_t *head = NULL;

//Insert at a given position
void add_at(int pos, int data)
{
	//Create the new node to be added
	node_t *node = malloc(sizeof(node_t)*1);
	node->data = data;
	node->next = NULL;

	//Is the list empty
	//If it is handle this case
	//If the list is empty, then node will be the first
	//And the head now points to the address of node
	if (head == NULL) {
		head = node;
		return;
	}

	//Otherwise, if the list is not empty
	//Now walk through linked list to desired position
	int i = 0;
	node_t *prev = NULL;
	node_t *curr = head;

	//Walk through
	//Curr == NULL when we are at the end of the list
	while (curr != NULL && i != pos) {
		++i; //Increment index
		prev = curr;//Record the current node as the previous
		curr = curr->next;//Walk to next node in list, the new current node
	} 

	//Here, curr is either null or at the desired position
	//If curr is null, add item to end of linked list
	//If curr is not null, shifting and inserting
	

	//New node is being inserted at beginning of the list
	if (i == 0) {
		head = node;
		node->next = curr;
		return;
	}

	//New node is being inserted at the end of the list
	if (curr == NULL) {
		prev->next = node;
		return;
	}

	//New node is being inserted at the pos i in the list
	node->next = curr;
	prev->next = node;
}

void add_start(int data)
{
	add_at(0, data);
}

void add_end(int data)
{
	add_at(-1, data); //Since index of i = -1 will cause us to walk the entire list
}

//Walk through list looking for either: Node that is null (reached the end)
//Or Node where the data matches the supplied data  you want to remove
void rem_data(int data)
{
	node_t *prev = NULL;
	node_t *curr = head;

	while (curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}

	//If curr == NULL, there is no match, do nothing
	if (curr == NULL) { 
		return; 
	}

	//If it i the first item in the list
	if (prev == NULL) {
		//List contains only 1 item
		if (curr->next == NULL) {
			head = NULL;
		} else {
			//List contains more than 1 item
			head = curr->next;
		}
		free(curr);
		return;
	}

	//If it, i, is the last item
	if (curr->next == NULL) {
		prev->next = NULL;
		free(curr);
		return;
	}

	if (prev != NULL && curr->next != NULL) {
		prev->next = curr->next;
		free(curr);
		return;
	}
	
}

void display()
{
	//Important notice***
	//Never use the Head to traverse, the head is the anchor that indicates the 
	//Beginning of the list
	//Lose the anchor, lose the list
	node_t *temp = head;
	int i = 0;
	while (temp != NULL) {
		printf("Data: %d, Node: %d\n", temp->data, i+1);
		temp = temp->next;
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;
	for (i = 1; i < argc; i++) {
		add_start(atoi(argv[i]));
	}

	display();
	rem_data(40);
	rem_data(20);
	display();
	return 0;
}
