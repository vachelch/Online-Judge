class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        def trans(c):
            if c == 'I':
                return 1
            elif c == 'V':
                return 5
            elif c == 'X':
                return 10
            elif c == 'L':
                return 50
            elif c == 'C':
                return 100
            elif c == 'D':
                return 500
            elif c == 'M':
                return 1000

        l = len(s)
        sum_ = trans(s[l-1])
        for i in range(l-2, -1, -1):
            num_1 = trans(s[i])
            num_2 = trans(s[i+1])
            if num_1 < num_2:
                sum_ = sum_ - num_1
            else:
                sum_ = sum_ + num_1
        return sum_