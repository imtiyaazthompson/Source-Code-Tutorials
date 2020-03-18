from py2neo import Graph, Node, Relationship

PASSWORD = 'rw334G2901*'

def welcome():
	print('Welcome to the Hello World of py2neo - Neo4j for Python!\n')

def init_graph(usrname, password):
	uri = 'http://localhost:7474/db/data/'
	username = 'neo4j'
	password = PASSWORD
	return Graph(uri,auth=(username, password))


'''
	Delete all nodes and relationships
'''
def clear_graph(graph):
	graph.delete_all()


def create_node(label, props):
	node = Node(label)
	for key in props.keys():
		node[key] = props[key]
	print(node)
	return node

def define_rel(src, rel, dest, props={}):
	rel = Relationship(src, rel, dest)
	for key in props.keys():
		rel[key] = props[key]
	return rel

def populate_graph(graph, nodes, relationships):
	for node in nodes:
		graph.create(node)
	for rel in relationships:
		graph.create(rel)
	

def main():
	g = init_graph('neo4j', PASSWORD)
	clear_graph(g)
	nodes = []
	relationships = []
	nodes.append(create_node('Person', {'name':'john','age':22}))
	nodes.append(create_node('Person', {'name':'alice', 'age':21}))
	relationships.append(define_rel(nodes[0], "MARRIED TO", nodes[1], {'years':10, 'happy':True}))
	
	populate_graph(g, nodes, relationships)

main()
