#include "../DoubleLinkedList/DoubleLinkedList.hpp"

template<typename T>
class Queue: protected List<T>{
    private:
        int size;
    public:
        Queue(): List<T>(), size(0) {}

        void enqueue(T val) {
            List<T>::insertTail(val);
            size++;
        }

        T dequeue() {
            if(List<T>::isEmpty())
                return 0;
            T toReturn = List<T>::getHead()->getVal();

            List<T>::removeHead();
            return toReturn;
        }


        friend ostream& operator<<(ostream& os, Queue<T>& queue) {
		    os << "Queue starting at " << queue.List<T>::getHead() << endl;
		    Node<T> *ptr = queue.List<T>::getHead();
		    while(ptr) {
			    os << ptr << endl;
			    ptr = ptr->getNext();
		    }
		    return os;
	    }
};
