// JavaScript: Scopes and Closures
function outerFunction() {
    let x = 10;  // Variable in the outer function scope
    
    function innerFunction() {
        console.log(x);  // Inner function uses variable from outer scope (closure)
    }
    
    innerFunction();
}

outerFunction();  // Output: 10
