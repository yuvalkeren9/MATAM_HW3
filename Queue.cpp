//
// Created by eladm on 21/05/2022.
//
#include <iostream>
#include "Queue.h"
using std::endl;
using std::cout;


void static setFortyTwo(int& n){
    n = 42;
}

static bool isEven(int n)
{
    return (n % 2) == 0;
}


int main(){
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);
    const Queue<int> queue2 = queue1;
    Queue<int> queue3 = filter(queue2, isEven);
    Queue<int> queue4 = filter(queue1, isEven);
    queue3.checkingIterator();
    queue4.checkingIterator();



}
/**implentation of list*/

