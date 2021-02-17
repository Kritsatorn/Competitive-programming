import time  
dict = {}
def fib(n) :
    if n in dict :
        return dict[n] 
    if n < 2 :
     return 1 

    dict[n] = fib(n-1) + fib(n-2)
    return dict[n]

    
start = time.time()
print(fib(100))
print("run time : {:.3f} " .format(time.time() - start))