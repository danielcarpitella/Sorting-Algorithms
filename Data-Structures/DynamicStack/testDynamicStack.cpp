#include "DynamicStack.hpp"

int main() {
    Stack<int> pila;

    pila.push(24323);
    pila.push(2);
    pila.push(43);
    pila.push(2);

    cout << pila << endl;

    int n1= pila.pop();
    int n2= pila.pop();

    cout << "Pop of " << n1 << ", " << n2 << endl;
    cout << pila << endl;

}