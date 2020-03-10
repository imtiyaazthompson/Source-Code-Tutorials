# Parsing Requirements (WIP)

This file details the requirements for parsing and retrieving data from the relevant *JSON* files.

## Parser Parameters
### Front End

The frontend should get (Form):
+ City
+ Cuisine Category
+ Day of Week
+ Time

The **DOW** and **Time** will be used to find restaurants that are open on that day and time. If *DOW* or *Time* is `NULL`, all restaurants
should be returned in the given **City** for the given **Cuisine Category**.


### JSON Parser
#### Nodes
The parser should read and retrieve data based in the criteria from the *Front End*

| Retrieve         | From          | As           |
|------------------|---------------|--------------|
| Restaurant name  | business.json | name         |
| Stars            | business.json | stars        |
| Review count     | business.json | review_count |

The above data forms a **Node** with `label="Restaurant"` with `properties={"name":name, "stars":stars, "review_count":review_count}`
Other possible **Nodes** could include:
+ `label="location"` with `properties={"city":city, "address":address, "state":state, "lat":latitude, "lon":longitude}`

*__Add more possible nodes if you see fit, however, each node that must me built requires more information to be retrieved from the JSON files__*

I have not yet figured out if we should create a *category* **Node**, since in **business.json** each business has list of categories e.g.
`"categories":"Italian, Restaurants, Pizza, Chicken Wings"`. Would appreciate input on how we should go about choosing what information actually
represents a **Node**.


#### Relationships
Given the **Nodes** `label="restaurant"` and `label="location"`
```python
	res = Node("Restaurant")
	loc = Node("Location")
```
Then a **Relationship**, as defined by the **Cypher** query language, is a direction between two nodes,

```python
	rel = Relationship(res, "LOCATED_IN", loc)
```

Printing out the contents of `rel` (`print(rel)`) yields
```python
	(res)-[:LOCATED_IN {}]->(loc)
```

**__Note__**: **Relationships** may also contain properties.

#### Building Nodes
**Nodes** need to be built from the data retrieved from the relevant **JSON** files
So, after reading the relevant data, that data gets passed to a function that will:
+ Build the **Node**
+ Append the **Node** to an array of Nodes

*__The above is just a very simple (maybe even inefficient) solution to a problem that may be much more complex.__*

#### Queries

