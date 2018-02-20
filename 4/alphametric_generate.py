import copy

left = []
right = []
vars = []
solution_count = 0
nonzero = set([])

checkpoint = [6, 7, 7]
checkflag = False 

f = open("alpha", "w")

def try_sol(sol):
	global vars, left, right, solution_count, nonzero
	global f
	if sol == []:
		return
	ll = copy.copy(left)
	for i in range(len(ll)):
		for j in range(0, len(vars)):
			ll[i] = ll[i].replace(vars[j], str(sol[j]))

	rr = copy.copy(right)
	for i in range(len(rr)):
		for j in range(0, len(vars)):
			rr[i] = rr[i].replace(vars[j], str(sol[j]))                

	if sum(map(int, ll)) != sum(map(int, rr)):
		return

	# found!
	for i in range(0, len(vars)):
		if (sol[i] == 0 and vars[i] in nonzero):
			return

	print ll, rr
	f.write(str(left) + ", " + str(right) + "\n")
	f.write(str(ll) + ", " + str(rr) + "\n")
	solution_count += 1

def per(s, l, k):
	if k == 0:
		try_sol(s)
		return
	for i in range(0, len(l)):
		per(s+[l[i]], l[0:i] + l[i+1:], k-1)

def solve():
	global vars, left, right, solution_count, nonzero
	s = set({})
	for x in left:	
		for c in x:
			s.add(c)
		nonzero.add(x[0])

	for x in right:	
		for c in x:
			s.add(c)
		nonzero.add(x[0])

	vars = list(s)
	if len(vars) > 10:
		return 0

	solution_count = 0
	per([], [0,1,2,3,4,5,6,7,8,9], len(vars))
	return solution_count

aa = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]

def test(leftnum, rightnum):
	global left, right
	left = map(lambda x: aa[x-1], leftnum)
	right = map(lambda x: aa[x-1], rightnum)

	print left, right

	llen = max(map(len, left))
	rlen = max(map(len, right))

	if llen > rlen:
		return

	if solve() == 1:
		print "found ", left, right
		f.write("found: " + str(left) + ", " + str(right) + "\n")

def partition(s, t, l, n, o):
	global checkpoint, checkflag
	if n < 0:
		return
	if n == 0:
		if len(s) == 1:
			return
		if checkflag:
			if s == checkpoint:
				checkflag = False
			else:
				return

		test(s, [o])
		return
	for i in range(t, l + 1):
		partition(s + [i], i, l, n-i, o)


#left = ["four", "one", "three", "three"]
#right = ["eleven"]
#left = ["manet", "matisse", "miro", "monet", "renoir"]
#right = ["artists"]
#left = ["eins", "eins", "eins", "eins"]
#right = ["vier"]
#left = ["forty", "ten", "ten"]
#right = ["sixty"]
#left = ["vingt", "cinq", "cinq"]
#right = ["trente"]
#left = ["coffee", "coffee", "coffee"]
#right = ["theorem"]

#test([1, 1, 1, 1, 1, 1, 1, 3, 3, 7], [20])

for i in range(11, 21):
	partition([], 1, i, i, i)
f.close()
