/* Write a program in either C++, Java, or C# that  illustrates the order of
 * evaluation of expressions used as actual parameters to a method.
 */
#include <iostream>

using namespace std;

int foo(int x) {
    return x * 10;
}

int main() {

    int x = 5;

    cout << "foo(x) = " << foo(x) << endl;           // 50
    cout << "foo(x++) = " << foo(x++) << endl;       // 50
    cout << "foo(x) = " << foo(x) << endl;           // 60
    cout << "foo(++x) = " << foo(++x) << endl;       // 70
    cout << "foo(x) = " << foo(x) << endl;           // 70
    cout << "foo(x += 1) = " << foo(x += 1) << endl; // 80
    cout << "foo(x) = " << foo(x) << endl;           // 80

    return 0;
}