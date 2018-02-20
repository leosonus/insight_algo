import copy

def next_per(l):
	t = len(l) - 2
	while t >= 0:
		if l[t] < l[t+1]:
			break
		t -= 1

	if t == -1:
		return []

	ll = l[t:]
	lll = sorted(ll)
	n = lll.index(ll[0])
	p = lll[n+1]
	del lll[n+1]

	lll.sort()
	lll.insert(0, p)

	return l[0:t] + lll

def inc(l):
	n = len(l) - 1
	while l[n] == 9 and n >=0:
		l[n] = 0
		n -= 1

	if n == -1:
		return []

	l[n] += 1
	return l

def next_case(l):
	l = inc(l)
	while len(l) != len(set(l)):
		l = inc(l)
	return l        


#left = ["four", "one", "three", "three"]
#right = ["eleven"]
#left = ["manet", "matisse", "miro", "monet", "renoir"]
#right = ["artists"]
left = ["eins", "eins", "eins", "eins"]
right = ["vier"]
#left = ["forty", "ten", "ten"]
#right = ["sixty"]
#left = ["vingt", "cinq", "cinq"]
#right = ["trente"]
#left = ["coffee", "coffee", "coffee"]
#right = ["theorem"]

print left, right

s = set({})

for x in left:	
	for c in x:
		s.add(c)

for x in right:	
	for c in x:
		s.add(c)

s = list(s)
print s
print len(s)

sol = [0] * len(s)
#sol = range(0, 10)

while True:
		sol = next_case(sol)
#		sol = next_per(sol)
		if sol == []:
			print 'done'
			break
		ll = copy.copy(left)
		for i in range(len(ll)):
			for j in range(0, len(s)):
				ll[i] = ll[i].replace(s[j], str(sol[j]))

		rr = copy.copy(right)
		for i in range(len(rr)):
			for j in range(0, len(s)):
				rr[i] = rr[i].replace(s[j], str(sol[j]))                


		if sum(map(int, ll)) == sum(map(int, rr)):
			print ll, rr
