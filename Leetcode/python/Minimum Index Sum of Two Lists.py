class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        idict = {}
        for i in range(len(list1)):
        	idict[list1[i]] = i

        res = []
        min_sum = 2000000000
        for i in range(len(list2)):
        	cantin = list2[i]
        	if cantin in idict:
        		sum_tmp = idict[cantin] + i
        		if sum_tmp < min_sum:
        			res = [cantin]
        			min_sum = min(min_sum, sum_tmp)
        		elif sum_tmp == min_sum:
        			res.append(cantin)

        return res










