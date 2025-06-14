import os

# This script lists all files and directories in a specified directory
directory_path='D:/memory/'   #variable to store the directory path

contents=os.listdir(directory_path)    #using os.listdir() to get the contents of the directory
# Print each item in the directory
for item in contents:
    print(item)

