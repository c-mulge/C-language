# Taking input from the user
# input() function is used to take input from the user

a=int(input("Enter an integer: "))  # Taking input as a string
b=float(input("Enter a float: "))  # Taking input as a string
c=input("Enter a string: ")  # Taking input as a string

print("Integer input:", a)
print("Float input:", b)
print("String input:", c)
# Note: The inputs are taken as strings. If you want to convert them to specific types, you can use int(), float(), etc.

# print("\n")
# print("Values are: ",a+b+c)
print("\n Types are: ",type(a),type(b),type(c))
# If you want to convert the inputs to specific types, you can do so like this:
