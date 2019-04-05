class Solution:
    def gcd(self, a, b):
        while b:
            tmp = a % b
            a = b
            b = tmp
            
        return a

    def lcm(self, a, b):
        return a*b/self.gcd(a, b)
    
    def get_nums(self, exp):
        return [int(num) for num in exp.split('/')]
    
    def add(self, res, num, sign = 1):
        if res[0] == 0: return (sign*num[0], num[1])

        nom = res[0]* num[1] + sign * res[1] * num[0]
        denom = res[1] * num[1]

        gcd = self.gcd(nom, denom)
        res = int(nom/abs(gcd)), int(denom/abs(gcd))
        return res
        
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        res = 0, 0
        start = 0
        expression += '+'
        oprator = ''

        for i in range(len(expression)):
            if expression[i] in ('-', '+'):
                if oprator == '-':
                    cur = self.get_nums(expression[start: i])
                    res = self.add(res, cur, -1)
                elif oprator == '+':
                    cur = self.get_nums(expression[start: i])
                    res = self.add(res, cur)
                else:
                    if i != 0:
                        res = self.get_nums(expression[start: i])
                start = i + 1
                oprator = expression[i];
        
        return str(res[0]) + '/' + str(res[1]);
            

s = Solution()
ipt = "-1/2+1/2"
print(s.fractionAddition(ipt))















