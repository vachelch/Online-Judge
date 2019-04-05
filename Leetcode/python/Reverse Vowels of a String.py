class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = len(s)
        ptr1 = 0
        ptr2 = l-1
        vowel = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        s = list(s)

        while ptr1 < ptr2:
            while ptr1 < l and s[ptr1] not in vowel:
                ptr1 += 1

            while ptr2 >= 0 and s[ptr2] not in vowel:
                ptr2 -= 1

            if ptr1 < ptr2:
                tmp = s[ptr1]
                s[ptr1] = s[ptr2]
                s[ptr2] = tmp
                ptr1 += 1
                ptr2 -= 1

        return ''.join(s)























