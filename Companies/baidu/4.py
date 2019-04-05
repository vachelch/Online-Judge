# KMP
# given string s, count how many different s' different with s
# s' comes from left rotate of s
# s = abab, s' = baba, abab, baba, abab. output 2
# eg:
# input
# abab
#
# output:
# 2

import sys

A = sys.stdin.readline().strip()
B = sys.stdin.readline().strip()
Q = int(sys.stdin.readline())

len_B = len(B)
hit = [0 for a in A]
for i in range(len(A)):
	if A[i:i+len_B] == B:
		hit[i+len_B-1] = 1

left = [0 for a in A]
right = [0 for a in A]

num = 0
for i in range(len(A)):
	num += hit[i]
	left[i] = num

for q in range(Q):
	row = sys.stdin.readline().strip()
	l, r = row.split()
	l = int(l) - 1
	r = int(r) - 1

	res = left[r] - left[l] + hit[l]
	for i in range(l, l+len_B-1):
		if (i <= r):
			res -= hit[i]

	print(res)

import sys

s = sys.stdin.readline().strip()

s2 = s
res = 0
s_len = len(s)
for i in range(s_len-1):
	s += s[i]
	if (s2 != s[i+1:]):
		res += 1
print(res)
