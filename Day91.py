functions = []
for i in range(10):
    functions.append(lambda i: i)
    
i = 0
for f in functions:
    print(f(i))
    i += 1
