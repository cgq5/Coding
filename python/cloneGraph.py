 #! /usr/bin/env python

"""
"""


from numpy import *

class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

def cloneGraph(node):
    if node == None:
        return None
    clone_node = UndirectedGraphNode(node.label)
    cloned, queue = {node: clone_node}, [node]
    
    while queue:
        curr = queue.pop()
        for neigh in curr.neighbors:
            if neigh not in cloned:
                queue.append(neigh)
                cloned_neighbor = UndirectedGraphNode(neigh)
                cloned[neigh] = cloned_neighbor
            cloned[curr].neighbors.append(cloned[neigh])
    return cloned[node]

def main():
    cloneGraph()

if __name__ == '__main__':
    main()
