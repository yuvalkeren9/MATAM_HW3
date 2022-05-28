//
// Created by eladm on 21/05/2022.
//
#include <iostream>
#include "Queue.h"
using std::endl;
using std::cout;

static void setSixtyNine(int& n)
{
    n = 69;
}

static bool isPrime(const int n)
{
    if (n < 2 || (n % 2 == 0 && n != 2))
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


void static setFortyTwo(int& n){
    n = 42;
}

static bool isEven(int n)
{
    return (n % 2) == 0;
}

class dividedBy {
private:
    int m_dividedBy;
public:
    explicit dividedBy(int n) : m_dividedBy(n) {}
    bool operator()(int number) const {
        return (number % m_dividedBy == 0);
    }
};

class removeLetter {
private:
    char m_letter;
public:
    explicit removeLetter(char c) : m_letter(c) {}
    bool operator()(char letter) const {
        return (m_letter != letter );
    }
};

class addTwo {
public:
     void operator()(int& data){
        data += 2;
    }
};


int main(){

    /** testing pushback & initiation with different types */
    Queue<int> queue1;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);
    queue1.checkingIterator();
    cout << endl;


    int swag1 = 1;
    int swag2 = 2;
    int swag3 = 3;


    cout << "checking queue that uses actual parameters " << endl;
    Queue<int> swagger;
    swagger.pushBack(swag1);
    swagger.pushBack(swag2);
    swagger.pushBack(swag3);
    swagger.checkingIterator();            //expecting 1 2 3
    cout <<endl;


    //copy constructor
    cout << "checking copy constructor " << endl;
    Queue<int> swagger1 = swagger;
    swagger1.pushBack(4);
    swagger1.checkingIterator(); //expecting 1 2 3 4
    cout <<endl;




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
    cout <<front1 << endl;
    char front2 = queue_char.front(); //expecting h
    cout <<front2 << endl;
    std::string front3 = queue_string.front(); //expecting Hi!
    cout <<front3 << endl;

    Queue<int> empty_queue;
    try {
        int swag = empty_queue.front(); //expcting error to be thrown to fail
    } catch (Queue<int>::EmptyQueue){
        cout << "Error was caught!" << endl;
    }
    cout << "Error was caught!" << endl;


    /**testing popfront method */
    queue1.popFront();
    queue1.popFront();
    cout << "expecting 3, actual value is:" << queue1.front() << endl;
    queue1.popFront();   //deleting 3
    queue1.popFront();   //deleting 4
    try{
        queue1.popFront();
    }catch (Queue<int>::EmptyQueue& e){
        cout <<"popFront error was caught!" <<endl;
    }
    try{
        queue1.front();
    } catch (Queue<int>::EmptyQueue& e){
        cout <<"front error was caught!" <<endl;
    }




    /** testing size method */
    cout <<endl << "Testing size method" << endl;
    cout << "The current size of queue1 is: " << queue1.size() <<endl;
    queue1.pushBack(1);
    queue1.pushBack(2);
    queue1.pushBack(3);
    queue1.pushBack(4);
    cout << "The size after pushing is: " << queue1.size() <<endl;
    cout << "The current size of queue_char is: " << queue_char.size() <<endl;
    cout << "The current size of queue_string is: " << queue_string.size() <<endl;

    /**testing filter function */
    queue1.pushBack(5);
    queue1.pushBack(6);




    cout <<endl << "Testing filter method" << endl;
    Queue<int> evenQueue = filter(queue1, isEven);
    cout << "Expecting 2 4 6:" << endl;
    evenQueue.checkingIterator();
    cout << "Expecting 1 2 3 4 5 6:" << endl;
    queue1.checkingIterator();
    dividedBy functor(3);
    Queue<int> queue_dividedBy3 = filter(queue1, functor);
    cout << "Expecting 3 6:" << endl;
    queue_dividedBy3.checkingIterator();
    removeLetter char_functor('l');
    Queue<char> newCharQue = filter(queue_char, char_functor);
    cout << "Expecting heo:" << endl;
    newCharQue.checkingIterator();


    cout <<endl << "Testing transform method" << endl;
    addTwo addTwofunctor;
    transform(queue1, addTwofunctor);
    cout << "Expecting  3 4 5 6 7 8:" << endl;
    queue1.checkingIterator();


    cout << endl << "Checking memory thing" << endl;
    Queue<int> NoaKirel = queue1;
    transform(NoaKirel, addTwofunctor);
    NoaKirel.checkingIterator();
    queue1.checkingIterator();

}

//int main(){
//
//    Queue<int> q;
//    for (int i = 0; i < 1984; i++){
//        q.pushBack(i);
//    }
//    cout << q.size() << endl;
//    Queue<int> primesQ = filter(q, isPrime);
//    cout << primesQ.size() << endl;
//    Queue<int> sixtyNineQ = primesQ;
//    cout << sixtyNineQ.size() <<endl;
//    transform(sixtyNineQ, setSixtyNine);
//    cout <<sixtyNineQ.size() << endl;
////    sixtyNineQ.checkingIterator();
//
//}

/**implentation of list*/

