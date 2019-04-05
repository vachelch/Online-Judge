class Solution:
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        idict = set(candies)
        kind = len(idict)
        l = len(candies)
        if kind <= l//2:
        	return kind
        return l//2
