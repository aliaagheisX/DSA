#include "LinkedList.cpp"
#include<iostream>
using std::cout;

int main() {
    LinkedList<int> l;
    l.addBack(1);
    l.addBack(1);
    l.addBack(2);
    l.addBack(3);
    l.addBack(5);
    l.addBack(6);
    l.addBack(7);
    l.addBack(7);
    l.Insert(2, 1);

    l.print();
    cout << '\n';

    l.removeFront();
    l.removeBack();
    
    l[0] = 10;
    l.removeIndex(1);
    l.print();
    cout << '\n';
    l.removeValue(3);
    l.print();
    cout << '\n';

    l.getBack() = 5;
    l.getFront() = 1;
    l.print();
    cout << '\n';

    LinkedList<int> l1(l);
    l1.addFront(5);
    l1 = l;
    l1.print();


    return 0;
}