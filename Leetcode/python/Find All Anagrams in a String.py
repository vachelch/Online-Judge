class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        lp = len(p)
        ls = len(s)
        res = []
        idict = {}
        for w in p:
            if w in idict: idict[w] += 1
            else: idict[w] = 1

        #check i-th word
        for i in range(ls-lp+1):
            if i == 0:
                tmp = {}
                for j in range(lp):
                    w = s[j]
                    if w in tmp: tmp[w] += 1
                    else: tmp[w] = 1

            else:
                w = s[i+lp-1]
                if w in tmp: tmp[w] += 1
                else: tmp[w] = 1

                tmp[s[i-1]] -= 1
            
            #check p and s
            anagram = 1
            for key, val in idict.items():
                if key not in tmp or tmp[key] != val: 
                    anagram = 0
                    break
            if anagram: res.append(i)
                
        return res






















