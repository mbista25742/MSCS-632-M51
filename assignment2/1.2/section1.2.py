# Python: Scopes and Closures
def outer_function():
    x = 10  # Variable in the outer scope
    
    def inner_function():
        print(x)  # Inner function uses variable from outer scope (closure)
    
    inner_function()

outer_function()  # Output: 10
