// C++: Scopes and Closures
#include <iostream>
using namespace std;

int main() {
    int x = 10;  // Variable in the local scope

    auto closure = [x]() {  // Lambda function captures x from the surrounding scope
        cout << x << endl;
    };

    closure();  // Output: 10
    return 0;
}
