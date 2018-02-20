def per(s, l, k):
    if k == 0:
        print s
        return
    for i in range(0, len(l)):
        per(s+[l[i]], l[0:i] + l[i+1:], k-1)

per([], [1,2,3,4], 4)
