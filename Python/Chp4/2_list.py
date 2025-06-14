fruits=["apple","banana","cherry","mango"]
print(fruits)

fruits.append("orange")
print(fruits)

l1=[1,12,56,3,2]
value=l1
# print(l1.sort())
l1.sort()
print(l1)
l1.reverse()
print(l1)
l1.insert(3,11)  #using insert function we can insert an element at a specific index
print(l1)
l1.pop(2)  #using pop function we can remove an element at a specific index
print(l1)

print("value",value)

l1.remove(12)  #using remove function we can remove an element by value
print(l1)