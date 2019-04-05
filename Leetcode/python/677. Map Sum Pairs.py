class TrieNode:
    def __init__(self):
        self.children = {}
        self.score = 0

class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = TrieNode()
        self.dic = {}

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        cur = self.trie
        delta = val - self.dic.get(key, 0)
        self.dic[key] = val
        for c in key:
            if c not in cur.children:
                node = TrieNode()
                node.score = delta
                cur.children[c] = node
            else:
                cur.children[c].score += delta
            cur = cur.children[c]

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        cur = self.trie
        for p in prefix:
            if p not in cur.children: return 0
            cur = cur.children[p]

        return cur.score


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)