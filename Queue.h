//
// Created by eladm on 21/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H

#include <iostream>
using std::endl;
using std::cout;

template<class T>
class Queue {
private:
    class Node;
    Queue<T>::Node* m_head;
    int m_size;
    class Iterator;

public:
    Queue();
    ~Queue();
    Queue(Queue& queue) = delete;
    void pushBack(T objectToPush);
    T& front() const;
    void popFront();
    int size() const;


    Queue<T>::Node* getLastNode() const;
    T getData() const;                  //delete my friend
    void checkingIterator() const;

    Iterator begin() const;
    Iterator end() const;

};
/***------------Queue methods--------------***/

/** Queue Constructor */
template<class T>
Queue<T>::Queue():m_head(nullptr),m_size(0) {}

/** Queue Destructor */
template<class T>
Queue<T>::~Queue(){
    while(this->m_head!= nullptr) {
        Node* toDelete = this->m_head;
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
}

template<class T>
void Queue<T>::pushBack(T objectToPush) {                   //allocate dymnic ?
    Queue<T>::Node* node = new Queue<T>::Node(objectToPush);
    Queue<T>::Node *currentLastNode = this->getLastNode();
    if (currentLastNode == nullptr){
        m_head = node;
        this->m_size++;
        return;
    }
    currentLastNode->m_next = node;
    this->m_size++;
}


template<class T>
T& Queue<T>::front() const{
    //if(this->m_size==0) {
    //    return nullptr;//check in piazza
    //}
        return this->m_head->m_data;
}

template<class T>
void Queue<T>::popFront(){
    if(this->m_size!=0) {
        if (this->m_size == 1) {
            delete m_head;
            m_head = nullptr;
            m_size = 0;
        } else {
            Queue<T>::Node* temp = this->m_head;
            this->m_head = this->m_head->m_next;
            delete temp;
            this->m_size--;
        }
    }
}

template<class T>
int Queue<T>::size() const{
    return this->m_size;
}


/***------------Queue begin--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    Iterator it(this, this->m_head);
    return it;
}
/***------------Queue end--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(this, nullptr);
}


/***------------Fucntions for testing Queue--------------***/
template <class T>
T Queue<T>::getData() const {
    return this->m_head->m_data;
}

template <class T>
void Queue<T>::checkingIterator() const{
    for (Iterator it = this->begin(); it != this->end(); ++it ){
        cout << it.m_ptrToNode->m_data << endl;

    }

}

/***------------Queue global functions--------------***/
template<class T, class Condition>
        Queue<T> filter(const Queue<T> &queue ,Condition c)
{
            Queue<T> newQueue;
            for(const T& data : queue) {
                if (c(data) == true){
                    newQueue.pushBack(data);
                }

            }
    return newQueue;

}

template<class T, class Transformation>
void transform(Queue<T> &queue ,Transformation transform)
{
    for(const T& data : queue){
        transform(data);
    }
}



/***-----------Iterator implication------------***/
template<class T>
class Queue<T>::Iterator{
private:
    const Queue<T>* m_queue;
    Node* m_ptrToNode;
    Iterator(const Queue<T>* queue, Node* ptrToNode);
    friend class Queue<T>::Node;
    friend class Queue<T>;
public:

    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Queue<T>::Iterator& iterator);



};
/** constructor of Iterator */
template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, Node* ptrToNode) : m_queue(queue), m_ptrToNode(ptrToNode){
        };


/** opertator* of Iterator */
template <class T>
T& Queue<T>::Iterator::operator*() const {
    return m_ptrToNode->m_data;
}

/** opertator++ of Iterator */
template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
    m_ptrToNode = m_ptrToNode->m_next;
    return *this;
}
/** opertator!= of Iterator */
template <class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator& iterator) {
    return (this->m_ptrToNode != iterator.m_ptrToNode);
}


/***-----------Node implication------------***/
template<class T>
class Queue<T>::Node{
public:
    ~Node()=default;
    Node (const Node& Node ) = delete;
private:
    T m_data;
    Node *m_next;
    explicit Node(T data);
    friend class Queue<T>;
    friend class Queue<T>::Iterator;
};


/***-----------Node methods------------***/

template<class T>
Queue<T>::Node::Node(T data):m_data(data){
    m_next=nullptr;
}






/**---------------helper function-------------**/
template<class T>
typename Queue<T>::Node* Queue<T>::getLastNode() const{//check for typename
    if (this->m_head == nullptr){
        return m_head;
    }
    Queue<T>::Node* temp= this->m_head;
    while (temp->m_next!= nullptr)
    {
        temp=temp->m_next;
    }
    return temp;
}


#endif //HW3_QUEUE_H
