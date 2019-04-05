class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        def in_row(s, set):
        	for w in s:
        		if w not in set: return False
        	return True

        row_u = set(['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'])
        row_m = set(['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'])
        row_l = set(['z', 'x', 'c', 'v', 'b', 'n', 'm'])

        res = []
        for word in words:
        	word_ = word.lower()
        	if in_row(word_, row_u) or in_row(word_, row_m) or in_row(word_, row_l):
        		res.append(word)

        return res