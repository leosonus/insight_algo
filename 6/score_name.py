import random
n = 1000000

s = ["hwang", "kim", "lee", "park", "choi", "jane", "cho", "park", "jung", "ko", "ha", "seo", "sun"]

print n
for i in range(n):
	print random.randrange(0, 1001), s[random.randrange(0, 10)]
	#print random.randrange(0, 1001)
