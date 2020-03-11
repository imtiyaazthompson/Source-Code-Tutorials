from py2neo import Graph, Node, Relationship

def welcome():
	print('Welcome to the Hello World of py2neo - Neo4j for Python!\n')

def init_graph():
	return Graph('bolt://ws-10-0-1-235-32979.neo4jsandbox.com:443')


def push(items, g):
	for item in items:
		g.create(item)
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

def main():
	g = init_graph()
	bob = create_node('Person', {'name':'john','age':22})
	alice = create_node('Person', {'name':'alice', 'age':21})
	rel = define_rel(bob, "MARRIED TO", alice, {'years':10, 'happy':True})
	g.create(rel)
	print(g)

main()
