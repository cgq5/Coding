 #! /usr/bin/env python

"""
build a Trie
"""


from numpy import *

class TrieNode:
    # Initialize your data structure here.
    def __init__(self):
        self.is_string = False
        self.children = {}
 
class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode() 

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        node = self.root
        for char in word:
            if not char in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_string = True

    def childSearch(self, word):
        node = self.root 
        for char in word:
            if char in node.children:
                node = node.children[char]
            else:
                return None
        return node 

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        node = self.childSearch(word)
        if node:
            return node.is_string
        return False 

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        node = self.childSearch(prefix) 
        return node != None

def main():
    # Your Trie object will be instantiated and called as such:
    obj = Trie()
    word = 'aeiou'
    obj.insert(word)
    param_2 = obj.search(word)
    param_3 = obj.startsWith('ae') 
    print param_3

if __name__ == '__main__':
    main()
