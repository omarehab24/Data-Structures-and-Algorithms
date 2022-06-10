# Undirected/connected Graph (All vertices are connected)
# O(1)
friends = { 
    "Alice": ["Bob", "Pam", "Jim"],
    "Bob": ["Alice", "Cynthia", "Diana"],
    #...
}

print(friends['Alice'])

# Directed Graph
followees = { 
    "Alice" : ["Bob", "Cynthia"], 
    "Bob": ["Cynthia"], 
    "Cynthia": ["Bob"]
}

# Object-Oriented Graph
class Vertex:
    def __init__(self, value):
        self.value = value
        self.adjacent_vertices = []

    def add_adjacent_vertex(self, vertex):
        #self.adjacent_vertices = [i for i in vertex] # list comprehension
        self.adjacent_vertices.append(vertex)
        
        # This will make the graph connected
"""         if self.adjacent_vertices.__contains__(vertex):
            return vertex.adjacent_vertices.append(self) """


omar = Vertex("omar")
yossef = Vertex("yossef")
ehab = Vertex("ehab")
mahmoud = Vertex("mahmoud")
ali = Vertex("ali")
ezz = Vertex("ezz")
print(omar.value)

omar.add_adjacent_vertex(yossef)
omar.add_adjacent_vertex(ehab)
yossef.add_adjacent_vertex(ali)
yossef.add_adjacent_vertex(mahmoud)
ehab.add_adjacent_vertex(ezz)

print([x.value for x in omar.adjacent_vertices])
print([x.value for x in yossef.adjacent_vertices])
print([x.value for x in ehab.adjacent_vertices])

#see page 360
# O(V + E) in a worst-case scenario
def dfs_traversal(vertex, visited_vertices={}):
    visited_vertices[vertex.value] = True
    print(vertex.value)

    for adjacent_vertex in vertex.adjacent_vertices:
        if adjacent_vertex.value in visited_vertices:
            continue
        dfs_traversal(adjacent_vertex, visited_vertices)
                
dfs_traversal(omar)



def dfs_search(vertex, search_value, visited_vertices={}):
    if vertex.value == search_value:
        return f"found {vertex.value}"

    visited_vertices[vertex.value] = True

    for adjacent_vertex in vertex.adjacent_vertices:
        if adjacent_vertex.value in visited_vertices:
                continue

        if adjacent_vertex.value == search_value:
            return f"found {adjacent_vertex.value}"

        vertex_tobe_searched = dfs_search(adjacent_vertex, search_value, visited_vertices)
    
        """ if vertex_tobe_searched:
            return vertex_tobe_searched """
    
    return "NULL"
    
print(dfs_search(omar, 'yossef'))
    


