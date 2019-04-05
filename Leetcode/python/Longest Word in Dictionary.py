class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        ans = ''
        length = 0
        iset = set(words)
        for word in words:
            l = len(word)
            if l < length: continue

            chag = 1
            for i in range(1, l):
                if word[:i] not in iset:
                    chag = 0
                    break
            if chag:
                if l > length:
                    length = max(length, l)
                    ans = word
                elif l == length and word < ans:
                    ans = word

        return ans