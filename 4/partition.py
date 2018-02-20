def partition(s, t, l, n):
	if n < 0:
		return
	if n == 0:
		print s
		return
	for i in range(t, l + 1):
		partition(s + [i], i, l, n-i)

partition([], 1, 10, 10)
