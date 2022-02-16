#include "LinkedList.cpp"
#include<iostream>
using std::cout;

int main() {
    LinkedList<int> l;

    int num = 73;
    int startMain = 5;


    
    int start = startMain;
    start--;

    for (int i = 0; i < num; i++) l.addBack(start++ % num + 1);
    LinkedList<int> l1(l);


    /*Solve thee 100 people in circle puzzle using circuilar doubly linked list*/

   
    ///First Approach

    // the cursor point initaly to last player
    l.advance(); // now to first

    while (l.getSize() != 1) {

        l.advance();//now to the killed player
        l.removeBack(); // remove the body and cursor return to killer
        l.advance();//advance to the next killer

    }

    l.print(); //print the only value in linkedlist
    cout << '\n';



    ///Second Approach
    l1.advance(); // now to first
    int n1 = log2(num);
    n1 = 1 << n1; //get the nearest power of 2
    for (int i = 0; i < n1;i++) {

        l1.advance();//now to the killed player
        l1.removeBack(); // remove the body and cursor return to killer
        l1.advance();//advance to the next killer

    }

    cout << l.getBack(); //print the one with gun  after the number of people become power of 2
    cout << '\n';



    ///solution using equation

    int n = log2(num);
    n = 1 << n; //get the nearest power of 2
    int r = (2 * (num - n) + startMain) % num;
    cout << r << '\n';


    return 0;
}