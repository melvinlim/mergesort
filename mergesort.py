def swap(ls,x,y):
	tmp=ls[x]
	ls[x]=ls[y]
	ls[y]=tmp
def merge(ls,a,b,c):
	n=b
	m=c
	x=[]
	a0=a
	while a<n and b<m:
		if ls[a]<=ls[b]:
			x.append(ls[a])
			a+=1
		else:
			x.append(ls[b])
			b+=1
	while a<n:
		x.append(ls[a])
		a+=1
	while b<n:
		x.append(ls[b])
		b+=1
	a=a0
	for e in x:
		ls[a]=e
		a+=1
	return
def mergesort(ls,a,n):
	if n<=1:
		return
	elif n==2:
		if ls[a]>ls[a+1]:
			swap(ls,a,a+1)
		return
	mid=n/2
	mergesort(ls,a,mid)
	mergesort(ls,a+mid,n-mid)
	merge(ls,a,a+mid,a+n)
import random
ITERS=1000
NELEMENTS=20
def sortOnce(NELEMENTS):
	print 'generating...'
	ls=random.sample(xrange(NELEMENTS),NELEMENTS)
	print ls
	print 'sorting...'
	a=0
	n=len(ls)
	mergesort(ls,a,n)
	print ls
for i in range(ITERS):
	print 'Iteration:',str(i)
	sortOnce(NELEMENTS)
	print
