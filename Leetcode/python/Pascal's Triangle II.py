class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        for i in range(0, rowIndex+1):
            pascal = []
            for j in range(i+1):
                if j == i or j == 0:
                    pascal.append(1)
                else:
                    pascal.append(last[j-1] + last[j])
            last = pascal[:]

        return pascal

s = Solution()
rowIndex = 2
print(s.getRow(rowIndex))
