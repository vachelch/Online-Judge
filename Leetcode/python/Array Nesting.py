class Solution:
    def arrayNesting(self, nums):
        mx = 0
        nest = set()
        for i in range(len(nums)):
            if nums[i] not in nest:
                iset = set()
                init = i

                index = i
                while 1:
                    if index in iset:
                        if index == init:
                            mx = max(len(iset), mx)
                        break

                    else:
                        iset.add(index)
                        index = nums[index]

                nest = nest | iset

        return mx



s = Solution()
nums = [5,4,0,3,1,6,2]
print(s.arrayNesting(nums))