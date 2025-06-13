import pyjokes

# comments here just press Ctrl + / to comment or uncomment

# for multiline comment we use triple quotes
"""
This is a multiline comment.
You can use it to explain the code in detail.
You can also use it to temporarily disable code.
"""
joke=pyjokes.get_joke()
print(joke)