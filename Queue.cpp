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

    int main() {

        /** testing pushback & initiation with different types */
        Queue<int> queue1;
        queue1.pushBack(1);
        queue1.pushBack(2);
        queue1.pushBack(3);
        queue1.pushBack(4);
        queue1.checkingIterator();
        cout << endl;


        //CHECK THAT MEMORY THINGY REALLY WORKS



        Queue<char> queue_char;
        queue_char.pushBack('h');
        queue_char.pushBack('e');
        queue_char.pushBack('l');
        queue_char.pushBack('l');
        queue_char.pushBack('o');
        queue_char.checkingIterator();
        cout << endl;

        Queue<std::string> queue_string;
        queue_string.pushBack("Hi!");
        queue_string.pushBack("my");
        queue_string.pushBack("name");
        queue_string.pushBack("is");
        queue_string.pushBack("Maor Edri");
        queue_string.checkingIterator();
        cout << endl;

        /**testing front method */
        int front1 = queue1.front(); //expecting 1
        cout << front1 << endl;
        char front2 = queue_char.front(); //expecting h
        cout << front2 << endl;
        std::string front3 = queue_string.front(); //expecting Hi!
        cout << front3 << endl;

        Queue<int> empty_queue;
        try {
            int swag = empty_queue.front(); //expcting error to be thrown to fail
        } catch (Queue<int>::EmptyQueue) {
            cout << "Error was caught!" << endl;
        }


    }
/**implentation of list*/

