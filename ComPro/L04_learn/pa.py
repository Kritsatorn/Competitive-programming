# Program to check if a string
#  is palindrome or not

# change this value for a different output
my_str = input('ENter : ')

# make it suitable for caseless comparison
my_str = my_str.casefold()

# reverse the string
rev_str = reversed(my_str)
print(rev_str)
# check if the string is equal to its reverse
if list(my_str) == list(rev_str):
   print("It is palindrome")
else:
   print("It is not palindrome")