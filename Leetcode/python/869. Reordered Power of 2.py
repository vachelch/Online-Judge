class Solution:
    def reorderedPowerOf2(self, N):
        """
        :type N: int
        :rtype: bool
        """
        N_str = str(N)
        l = len(N_str)

        power = 1
        recorder = []
        for i in range(33):
        	power_str = str(power)
        	if len(power_str) == l:
        		recorder.append(power_str)
        	power *= 2

        recorder_dicts = []
        for pow_str in recorder:
        	pow_dict = {}
        	for c in pow_str:
        		if c in pow_dict:
        			pow_dict[c] += 1
        		else:
        			pow_dict[c] = 1

        	recorder_dicts.append(pow_dict)

        N_dict = {}
        for c in N_str:
        	if c in N_dict:
        		N_dict[c] += 1
        	else:
        		N_dict[c] = 1

        for pow_dict in recorder_dicts:
        	flag = 1
        	for key, val in pow_dict.items():
        		if key not in N_dict or N_dict[key] != val:
        			flag = 0
        			break

        	if flag:
        		return True

        return False

s = Solution()
print(s.reorderedPowerOf2(46))







