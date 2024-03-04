#include "../DoubleLinkedList/DoubleLinkedList.hpp"

template<typename T>
class Stack: protected List<T> {
    private:
        int size;
    public:
        Stack(): List<T>(), size(0) {}

        bool isEmpty() {return size == 0;}

        Node<T>* top() {
            if(this->isEmpty())
                return nullptr;
            return List<T>::getHead();
        }

        void push(T val) {
            List<T>::insertHead(val);
            size++;
        }

        T pop() {
            if(this->isEmpty())
                return NULL;
            T value = top()->getVal();

            List<T>::removeHead();
		    size--;

            return value;
        }

        friend ostream& operator<<(ostream& os, Stack<T>& s) {
            Node<T>* ptr = s.List<T>::getHead();
            while(ptr) {
                os << ptr << endl;
                ptr = ptr->getNext();
            }

            return os;

        }
    

};