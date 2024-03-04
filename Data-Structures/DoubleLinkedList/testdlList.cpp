#include "DoubleLinkedList.hpp"

int main() {
    List<int> lista;

    // testing inserting methods
    lista.insertInOrder(1234);
    lista.insertInOrder(123324);
    lista.insertInOrder(4);
    lista.insertInOrder(34);

    cout << lista << endl;


    //testing removing methods
    lista.removeNode(4);
    lista.removeNode(34);
    //lista.removeNode(123324);
    lista.removeNode(342432);
    

    cout << lista << endl;
}