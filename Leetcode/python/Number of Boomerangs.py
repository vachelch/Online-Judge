class Solution:
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        iset = {}
        count = 0
        for point in points:
        	for p in points:
        		if p != point:
        			distance = (p[0] - point[0])*(p[0] - point[0]) + (p[1] - point[1])*(p[1] - point[1])
        			if distance in iset:
        				iset[distance] += 1
        			else:
        				iset[distance] = 1

        	for key, val in iset.items():
        		count += val*(val-1)
        	iset = {}
        return count


