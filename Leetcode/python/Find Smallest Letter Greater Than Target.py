class Solution:
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        ot = ord(target)
        for c in letters:
        	if ord(c) > ot: return c
        return letters[0]

