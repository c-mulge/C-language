a=(1,45,342,True,"abc," "def")
# print(a[0])  # Output: 1

# a[0]=100  # This will raise an error because tuples are immutable

print(a)
print(type(a))  # Output: <class 'tuple'>

n=a.count(1)   #true is also considered as 1
print(n)  # Output: 2

i=a.index(45)
print(i)  # Output: 1