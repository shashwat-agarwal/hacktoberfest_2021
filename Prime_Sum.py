PRIME SUM :

code :

def isprime(n):
    if n==1:
        return 0
    else:
        for i in range(2,n):
            if(n%i==0):
                return 0
        return 1
print("Enter the number")
A=int(input())
l=[]
i=A-1
while(i>=2):
    if(isprime(i)==1 and isprime(A-i)==1):
        l.append(i)
        l.append(A-i)
        break
    i-=2
if(len(l)==0):
    if(isprime(A-2)==1):
        l.append(2)
        l.append(A-2)
l=sorted(l)
print(*l)

Output :

Enter the number
8
3 5
