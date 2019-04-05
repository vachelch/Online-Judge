class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        if len(indexes) == 0: return S

        datas = []
        for i in range(len(indexes)):
        	row = []
        	row.append(indexes[i])
        	row.append(sources[i])
        	row.append(targets[i])
        	datas.append(row)

        datas = sorted(datas, key= lambda x: x[0])

        start = 0
        end = datas[0][0]
        sub_str = [S[start: end]]
        for i in range(len(indexes)-1):
        	start = datas[i][0]
        	end = datas[i][0] + len(datas[i][1])
        	end2 = datas[i+1][0]

        	str1 = S[start: end]
        	str2 = S[end: end2]

        	sub_str.append(str1)
        	sub_str.append(str2)

        start = datas[-1][0]
        end = datas[-1][0] + len(datas[-1][1])
        end2 = len(S)

        str1 = S[start: end]
        str2 = S[end:]

        sub_str.append(str1)
        sub_str.append(str2)

        res = sub_str[0]

        for i in range(len(targets)):
        	if sub_str[2*i + 1] == datas[i][1]:
        		res += datas[i][2]
        	else:
        		res += sub_str[2*i + 1]

        	res += sub_str[2*i + 2]

        return res



s = Solution()
S = "vmokgggqzp"
indexes = [3, 5, 1]
sources = ["kg","ggq","mo"]
targets = ["s","so","bfr"]
print(s.findReplaceString(S, indexes, sources, targets))


