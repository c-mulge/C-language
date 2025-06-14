name="channveer"

print(len(name))
print(name.endswith("er"))
print(name.startswith("Ch"))  #returns false because this function is casesensitive

print(name.capitalize())  # Capitalizes the first letter of the string
print(name)  # Original string remains unchanged

print(name.upper())  # Converts the string to uppercase
print(name.lower())
print(name.count("n"))  # Counts the occurrences of 'n' in the string
print(name.find("n"))  # Finds the first occurrence of 'n' and returns its index

print(name.replace("n","N")) # Replaces 'n' with 'N' in the string
print(name)  # Original string remains unchanged
print(name.split(","))