import keyword
keyword_list = keyword.kwlist
"""
'''
finding identifiers
"""
'''
identifiers = variable_name + function_name
'''
"""
finding identifiers2
"""
def remove_docstring_comments(long_line) :
  pos= 0
  status = True
  new_long_line = ''
  while status :
    status= False
    index1_docstr = long_line.find('\"\"\"', pos)
    index1_comment = long_line.find('\'\'\'', pos)
    # print(index1_docstr, index1_comment)
    # if (index1_docstr < index1_comment and index1_docstr >= 0) or (index1_docstr >= 0 and index1_comment < 0) :
    if index1_docstr >= 0 and (index1_docstr < index1_comment or index1_comment < 0) :
      # print(index1)
      index2 = long_line.find('\"\"\"', index1_docstr+3)
      # print(index2)
      new_long_line += long_line[pos:index1_docstr]
      #print(long_line[index1_docstr:index2+3])
      pos = index2 + 3
      status = True
    elif (index1_comment < index1_docstr and index1_comment >= 0) or (index1_comment >= 0 and index1_docstr < 0) :
      # print(index1)
      index2 = long_line.find('\'\'\'', index1_comment+3)
      # print(index2)
      new_long_line += long_line[pos:index1_comment]
      #print(long_line[index1_comment:index2+3])
      pos = index2 + 3
      status = True
  new_long_line += long_line[pos:]
  return new_long_line

def remove_str(line) :
  new_line = ''
  # ....
  return new_line

filename = "identify.py"
# reading file
long_line = open(filename).read()
# print(long_line)
# remove docstrings & manylinescomment
long_line = remove_docstring_comments(long_line)
# print(long_line)
# split lines
lines = long_line.split('\n')
print(lines)
for line in lines :
  # for each line remove string
  line = remove_str(line)
  # for each line remove line comment
  # remove text behind the '#'
  #line = remove_comment(line)
  # for each line remove special characters
  # contain only 'A'-'Z', 'a'-'z', '0'-'9', '_'
  # for each line remove number
  # '1'.isdigit()

# remove reserved words
#print(keyword_list)

# collect identifiers in dict & show