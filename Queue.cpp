//
// Created by eladm on 21/05/2022.
//
#include <iostream>
using std::endl;
using std::cout;


void static setFortyTwo(int& n){
    n = 42;
}

static bool isEven(int n)
{
    return (n % 2) == 0;
}


#include "Queue.h"
int main(){
    Queue<int> queue;
    queue.pushBack(1);
    queue.checkingIterator();
    cout << endl;

    Queue<int> queue53 = queue;
    //test empty queue with transform and filter
    Queue<int> queue2;
    queue2 = queue;
    queue2.popFront();
    queue2.checkingIterator();
    cout << endl;

    queue.checkingIterator();
    cout << endl;

    Queue<int> queue3 = queue;
    queue3.popFront();
    queue3.popFront();
    queue3.checkingIterator();

    Queue<int> queue4 = filter(queue, isEven);
    queue4.checkingIterator();
    if(queue53 == queue){
        cout << "TRUE!" << endl;
    }
    else{
        cout <<"FALSE!" <<endl;
    }

  //  queue2.checkingIterator();



}
/**implentation of list*/

