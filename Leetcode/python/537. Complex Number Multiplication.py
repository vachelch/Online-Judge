class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        str1, str2 = a.split('+')
        a_num1 = int(str1)
        a_num2 = int(str2[:-1])
        
        str1, str2 = b.split('+')
        b_num1 = int(str1)
        b_num2 = int(str2[:-1])
        
        res1 = a_num1 * b_num1 - a_num2 * b_num2
        res2 = a_num1*b_num2 + a_num2*b_num1 
        
        res = str(res1) + '+' + str(res2) + 'i'
        
        return res