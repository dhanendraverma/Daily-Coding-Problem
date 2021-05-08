'''
/***************************************************************************************************************************************
Good morning! Here's your coding interview problem for today.
This problem was asked by Google.
What will this code print out?
def make_functions():
    flist = []
    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)
    return flist
functions = make_functions()
for f in functions:
    f()
How can we make it print out what we apparently want?
***************************************************************************************************************************************/
'''
# Output of the code would be : 3 3 3 reason behind this is a closure caputures the variable, not the current variable value, for all the functios being 
# appended to the flist the same variale i is shared among them meaning that each i appended to the function refers to the same memory loction,  
# since last value stored to the location is 3 hence all three run would output same value.In order to make this work as expected we can get each function it's
# own scope variable which would help to maintain the value coming from list in variable named i which has scope local to the function and hence value stored at 
# each referece would be the value of i at that particalar instace of loop.

def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i(i=i):
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f() 
    
#output = 1 2 3
# the local binding of the value in variabel i to the scope of the function by using the assignment i==i we can now refer to the value
# of i when the function was being appended to the list.
