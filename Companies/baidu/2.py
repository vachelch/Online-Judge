# 编号转换（百度2016实习生真题）
# 81%, WA
import sys


def chr2num(row):
	c = 0
	for alpha in row:
		c = c*26 + (ord(alpha) - ord('A') + 1)
	return c

def num2chr(c):
	res = ""
	while c:
		mod = (c-1) % 26
		res = chr(ord('A') + mod) + res
		c //= 26

	return res

def A2B(row):
	start = 0
	cur = 0
	while(ord('A') <= ord(row[cur]) <= ord('Z')):
		cur += 1

	c = chr2num(row[start: cur])
	r = int(row[cur:])

	return "R%dC%d"%(r, c)

def B2A(row):
	c_idx = 0
	while row[c_idx] != 'C':
		c_idx += 1

	r = int(row[1:c_idx])
	c = int(row[c_idx+1:])

	alpha = num2chr(c)

	return alpha + str(r)



def find_num_first_end(row):
	idx = 0
	while(ord('A') <= ord(row[idx]) <= ord('Z')):
		idx += 1

	while(idx < len(row) and ord('0') <= ord(row[idx]) <= ord('9')):
		idx += 1

	return idx
	


T = sys.stdin.readline()
T = int(T)
for row in range(T):
	row = sys.stdin.readline().strip()
	idx = find_num_first_end(row)
	if idx == len(row):
		res = A2B(row)
	else:
		res = B2A(row)

	print(res)

