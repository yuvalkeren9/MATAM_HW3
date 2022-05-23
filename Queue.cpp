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
    queue.pushBack(2);
    queue.pushBack(3);
    queue.pushBack(4);
    queue.checkingIterator();

    Queue<int> queue2;
    queue2 = queue;
    queue2.popFront();
    queue2.checkingIterator();


    Queue<int> queue3 = queue;
    queue3.popFront();
    queue3.popFront();
    queue3.checkingIterator();

    Queue<int> queue4 = filter(queue, isEven);
    queue4.checkingIterator();

  //  queue2.checkingIterator();



}
/**implentation of list*/

