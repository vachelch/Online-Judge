class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        dict_ = {}
        for a in A.split():
        	if a not in dict_:
        		dict_[a] = 1
        	else:
        		dict_[a] += 1


        for b in B.split():
        	if b not in dict_:
        		dict_[b] = 1
        	else:
        		dict_[b] += 1

        res = []
        for key, value in dict_.items():
        	if value == 1:
        		res.append(key)

        return res