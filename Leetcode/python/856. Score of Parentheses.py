from collections import deque

class Solution:
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        q = deque()

        add_one = 1
        for s in S:
            if s == ')':
                if q[-1] == '(' and add_one == 1:
                    q.pop()
                    q.append(1)
                else:
                    # do pop q until get a '('
                    res = 0
                    while 1:
                        tmp = q.pop()
                        if tmp == '(':
                            break
                        res = int(tmp) + res
                    res *= 2
                    q.append(res)
                add_one = 0
            elif s == '(':
                q.append(s)
                add_one = 1
            else:
                q.append(s)

        res = 0
        while len(q):
            res += int(q.pop())

        return res

s = Solution()
print(s.scoreOfParentheses("(()(()))"))






