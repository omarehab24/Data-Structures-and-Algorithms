from queue import *

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


# O(V + E) in a worst-case scenario
def bfs_traversal(starting_vertex):
    queue = Queue()

    visited_vertices = {}
    visited_vertices[starting_vertex.value] = True

    queue.put(starting_vertex)

    while(not queue.empty()):
        current_vertex = queue.get()
        print(current_vertex.value)

        for adjacent_vertex in current_vertex.adjacent_vertices:
            if not adjacent_vertex.value in visited_vertices:
                visited_vertices[adjacent_vertex.value] = True
                queue.put(adjacent_vertex)

bfs_traversal(omar)