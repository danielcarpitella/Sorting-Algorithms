#include "DynamicQueue.hpp"

int main() {
    Queue<int> coda;

    coda.enqueue(132);
    coda.enqueue(13);
    coda.enqueue(1223);
    coda.enqueue(12323);
    coda.enqueue(3);

    cout << coda << endl;

    int n1 = coda.dequeue();
    int n2 = coda.dequeue();

    cout << "Dequeue of " << n1 << ", " << n2 << endl;

    cout << coda << endl;
}

