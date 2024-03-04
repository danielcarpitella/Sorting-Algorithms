#include "Bts.hpp"

int main() {
    BST<int> bst;

    
    bst.insert(3);
    bst.insert(241);
    bst.insert(432);
    bst.insert(24241);
    
    cout << "bst with heigth: " << bst.heigth() << endl;
    bst.inorder();
    cout << endl;

    cout << "The successor of 3 in the BST is " << bst.successor(3) << endl;
    cout << "The predecessor of 24241 in the BST is " << bst.predecessor(bst.search(24241)) << endl;

    bst.remove(241);
    bst.remove(23213);
    bst.remove(432);
    
    cout << "bst with heigth: " << bst.heigth() << endl;
    bst.inorder();
    cout << endl;

    
}