#include <iostream>

using namespace std;

template<typename T> 
class Node{
    private:
        T val;
        Node<T>* next;
        Node<T>* prev;

        template<typename U>
        friend class List;

    public:
        Node(T key): val(key), next(nullptr), prev(nullptr) {}

        T& getVal() {return this->val;}

        Node<T>* getNext() {return this->next;}

        friend ostream& operator<<(ostream& os, Node<T>* nodo) {
            if(nodo)
                os << nodo->val << " ";
            else
                os << "No existing Node" << endl;
            return os;
        }
};


template<typename T>
class List{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        List(): head(nullptr), tail(nullptr) {}

        bool isEmpty() {return head == nullptr;}

        Node<T>* getHead() {return this->head;}
        Node<T>* getTail() {return this->tail;}

        void insertHead(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                tail = head;
                return;
            }

            Node<T>* toInsert = new Node<T>(val);
            toInsert->next = head;
            head->prev = toInsert;
            head = toInsert;
        }

        void insertTail(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                tail = head;
                return;
            }

            
            Node<T>* toInsert = new Node<T>(val);
            toInsert->prev = tail;
            tail->next = toInsert;
            tail = toInsert;
            
        }


        void insertInOrder(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val);
                tail = head;
                return;
            }

            if(head->val > val) {
                this->insertHead(val);
                return;
            }

            Node<T>* ptr = this->head;
            while(ptr->next && ptr->val <= val) {
                if(ptr->next->val > val)
                    break;
                ptr = ptr->next;
            }


            if(!(ptr->next)) {
                this->insertTail(val);
                return;
            }


            Node<T>* toInsert = new Node<T>(val);
            toInsert->next = ptr->next;
            toInsert->prev = ptr;

            ptr->next->prev = toInsert;
            ptr->next = toInsert;
        }


        void removeHead() {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }

            if(head == tail) {
                Node<T>* ptr = head;
                head = nullptr;
                tail = nullptr;
                delete ptr;
                return;
            }

            Node<T>* ptr = head;
            head->next->prev = nullptr;
            head = head->next;
            delete ptr;
        }


        void removeTail() {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }


            if(head == tail) {
                Node<T>* ptr = head;
                head = nullptr;
                tail = nullptr;
                delete ptr;
                return;
            }

            Node<T>* ptr = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete ptr;
        }


        void removeNode(T val) {
            if(this->isEmpty()) {
                cout << "Empty List! Nothing to remove" << endl;
                return;
            }

            if(head->val == val) {
                removeHead();
                return;
            }

            Node<T>* cur = head;
            
            while(cur->next && cur->val != val) {
                cur = cur->next;
            }            

            if(!(cur->next) && cur->val == val) {
                removeTail();
                return;
            }else if(!(cur->next) && cur->val != val) {
                cout << "Value "<< val << " to remove not found!" << endl;
                return;
            }

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;

            delete cur;
        }



        friend ostream& operator<<(ostream& os, const List<T>& lista) {
            Node<T>* ptr = lista.head;
            os << "List Head: " << ptr << endl;
            while(ptr) {
                os << ptr << endl;
                ptr = ptr->getNext();
            }
            os << endl << endl;
            return os;
        }
};