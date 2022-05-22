//
// Created by eladm on 21/05/2022.
//
#include <iostream>
using std::endl;
using std::cout;

#include "Queue.h"
int main(){
    Queue<int> queue;
    queue.pushBack(1);
    queue.pushBack(2);
    queue.pushBack(5);
    queue.pushBack(7);
    queue.popFront();
    int swag = queue.getData();
    queue.checkingIterator();
    return 0;
}
/**implentation of list*/

