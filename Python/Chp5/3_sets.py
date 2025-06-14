s={1,2,3}
# print(s,type(s))

s.add(4)  # Adding an element to the set
# print(s)

a = {1, 2, 3}
b = {3, 4, 5}

print(a | b)   # Union → {1, 2, 3, 4, 5}
print(a & b)   # Intersection → {3}
print(a - b)   # Difference → {1, 2}
print(b - a)   # Difference → {4, 5}
print(a ^ b)   # Symmetric Difference → {1, 2, 4, 5}
