def swap(ls,x,y):
	tmp=ls[x]
	ls[x]=ls[y]
	ls[y]=tmp
def merge(a,b):
	c=[]
	n=len(a)
	m=len(b)
	i=0
	j=0
	while i<n and j<m:
		if a[i]<=b[j]:
			c.append(a[i])
			i+=1
		else:
			c.append(b[j])
			j+=1
	return c+a[i:]+b[j:]
def mergesort(ls):
#	print 'merging:',ls
	n=len(ls)
	if n<=1:
		return ls
	elif n==2:
		if ls[0]>ls[1]:
			swap(ls,0,1)
		return ls
	mid=n/2
	l=ls[:mid]
	r=ls[mid:]
	l=mergesort(l)
	r=mergesort(r)
	return merge(l,r)
import random
NELEMENTS=20
ls=random.sample(xrange(NELEMENTS),NELEMENTS)
print ls
print 'sorting...'
ls=mergesort(ls)
print ls
