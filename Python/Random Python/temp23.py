
def fib(n):    #The keyword def introduces a function definition.
    a,b=0,1
    while a<n:
        print(a, end=' ')
        a,b=b,a+b
    print()

# fib(1000)
f=fib
# f(100)
abc=f
abc(100)