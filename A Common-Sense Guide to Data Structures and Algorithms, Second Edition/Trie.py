


class TrieNode:
    def __init__(self):
        self.children = {}


class Trie:
    def __init__(self):
        self.root = TrieNode() # self.root points to the root node, when we create a new Trie, it begins with an empty TrieNode as its root.

    # O(K)
    def insert(self, word):
        currentNode = self.root # Set root node as the currentNode
        
        for char in word: # For each character in our string
            if currentNode.children.get(char):
                currentNode = currentNode.children[char]
            else:
                # If the current character isn't found among the current node's children, we add the character as a new child node.
                newNode = TrieNode() 
                currentNode.children[char] = newNode

                currentNode = newNode # Follow this new node

        currentNode.children["*"] = None


    # O(K)
    def search(self, word):
        currentNode = self.root

        for char in word:
            if currentNode.children.get(char):
                currentNode = currentNode.children[char]
            else:
                print("Not Found!")
                return None # If the current character isn't found among # the current node's children, our search word # must not be in the trie
        
        print("Found!")
        return currentNode # If we get past the end of the loop, it means we’ve found the entire word in our trie. In this case, we return the currentNode.
        

    def collectAllWords(self, node=None, word="", words=[]):
        # This method accepts three arguments. The first is the node whose descendants we're collecting words from. 
        # The second argument, word, begins as an empty string, and we add characters to it as we move through the trie. 
        # The third argument, words, begins as an empty array, and by the end of the function will contain all the words # from the trie.

        currentNode = node or self.root # The current node is the node passed in as the first parameter, or the root node if none is provided

        # we begin a loop that iterates over all the key-value pairs in the currentNode’s children hash table, In each iteration of the loop, the key is always a single-character string, and the value, childNode, is another instance of TrieNode.
        for key, childNode in currentNode.children.items():
            # If the current key is *, it means we hit the end of a complete word, so we can add it to our words array. (The base case)
            if key == "*":
                words.append(word)
            # If we're still in the middle of a word: We recursively call this function on the child node.
            else:
                self.collectAllWords(childNode, word+key, words)

        return words


    def autoComplete(self, prefix):
        """First, we search the trie for the existence of the prefix. If the search method doesn’t find the prefix in the trie, it returns None. However, if the prefix is found in the trie, the method returns the node in the trie that represents the final character in the prefix."""
        currentNode = self.search(prefix)

        if not currentNode:
            return None

        """Our autocomplete method continues by calling the collectAllWords method on the node returned by the search method. This finds and collects all words that stem from that final node, which represent all the complete words that can be appended to the original prefix to form a word. 
        Our method finally returns an array of all possible endings to the user’s prefix, which we could then display to the user as possible autocomplete options."""
        return self.collectAllWords(currentNode)





      
trie = Trie()
trie.insert("cat")
trie.insert("can")

trie.search("cat")

trie_words = trie.collectAllWords()
print(trie_words)

trie_autoComplete = trie.autoComplete("c")
print(trie_autoComplete)




