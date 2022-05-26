
#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H

#include <iostream>
using std::endl;
using std::cout;

template<class T>
class Queue {
private:
    class Node;
    int m_size;
    Queue<T>::Node* m_head;

public:
    class Iterator;
    class ConstIterator;
    Queue();
    ~Queue();
    Queue(const Queue<T>& queue);
    class EmptyQueue{};

    Queue<T>& operator=(const Queue<T>& queue);

    template<class S>
    friend bool operator==(const Queue<S>& queue1, Queue<S>& queue2);

    void pushBack(T objectToPush);
    T& front() const;
    void popFront();
    int size() const;
    Queue<T>::Node* getLastNode() const;
    void checkingIterator() const;                  //keep for possible future tests
    Iterator begin();
    Iterator end();
    ConstIterator begin() const;
    ConstIterator end() const;

};
/***------------Queue methods--------------***/

/** Queue Constructor */
template<class T>
Queue<T>::Queue():m_size(0), m_head(nullptr) {}

/** Queue Destructor */
template<class T>
Queue<T>::~Queue(){
    while(this->m_head!= nullptr) {
        Node* toDelete = this->m_head;
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
}


/**  copy constructor Queue*/

template<class T>                          //MAKING CHANGE HERE
Queue<T>::Queue(const Queue<T> &queue) :m_size(queue.size()), m_head(nullptr){
    try {
        for (ConstIterator it = queue.begin(); it != queue.end(); ++it) {
            this->pushBack(*it);
        }
    } catch (typename Queue<T>::ConstIterator::InvalidOperation& e){}
}





/** operator== of queue */
template<class S>
bool operator==(const Queue<S>& queue1, Queue<S>& queue2){
    if(queue1.m_head == queue2.m_head){
        return true;
    }
    else{
        return false;
    }
}
/** operator = of Queue*/
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue) {
    if (this == &queue){
        return *this;
    }
    m_size = queue.size();
    try {
        for (ConstIterator it = queue.begin(); it != queue.end(); ++it) {
            this->pushBack(*it);
        }
    } catch (typename Queue<T>::ConstIterator::InvalidOperation& e){}
    return *this;

}

template<class T>
void Queue<T>::pushBack(T objectToPush) {
    try {
        Queue<T>::Node* node = new Queue<T>::Node(objectToPush);
        Queue<T>::Node *currentLastNode = this->getLastNode();
        if (currentLastNode == nullptr){
            m_head = node;
            this->m_size++;
            return;
        }
        currentLastNode->m_next = node;
        this->m_size++;
    } catch(std::bad_alloc& e) {
        throw std::bad_alloc();
    }
}



template<class T>
T& Queue<T>::front() const{
    if (this->m_size == 0){
        throw EmptyQueue();
    }
    return this->m_head->m_data;
}

template<class T>
void Queue<T>::popFront(){
    if (this->m_size == 0){
        throw EmptyQueue();
    }
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

template<class T>
int Queue<T>::size() const{
    return this->m_size;
}


/***------------Queue begin--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::begin()  {
    Iterator it(this, this->m_head);
    return it;
}
/***------------Queue end--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::end()  {
    return Iterator(this, nullptr);
}

/***------------Queue begin const--------------***/
template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const  {
    ConstIterator it(this, this->m_head);
    return it;
}
/***------------Queue end const--------------***/
template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const  {
    return ConstIterator(this, nullptr);
}



/***------------Fucntions for testing Queue--------------***/

template <class T>
void Queue<T>::checkingIterator() const{
    try {
        for (ConstIterator it = this->begin(); it != this->end(); ++it ){
            cout << it.m_ptrToNode->m_data << endl;
        }
    } catch (typename Queue<T>::Iterator::InvalidOperation& e){

    }
    catch (typename Queue<T>::ConstIterator::InvalidOperation& e){

    }
}

/***------------Queue global functions--------------***/
//template<class T, class Condition>
//Queue<T> filter(Queue<T> &queue ,Condition condition)    //deleted const here undeleted
//{
//            Queue<T> newQueue;
//            for(T& data : queue) {    //made change here
//                if (condition(data) == true){
//                    newQueue.pushBack(data);
//                }
//            }
//    return newQueue;
//
//}

template<class T, class Condition>
Queue<T> filter(const Queue<T> &queue ,const Condition condition)    //deleted const here undeleted
{
    Queue<T> newQueue;
    for(const T& data : queue) {    //made change here
        if (condition(data) == true){
            newQueue.pushBack(data);
        }
    }
    return newQueue;

}

template<class T, class Operation>
void transform(Queue<T> &queue ,Operation operation)
{
    for(T& data : queue){
        operation(data);
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
    class InvalidOperation{};
};
/** constructor of Iterator */
template <class T>
Queue<T>::Iterator::Iterator(const Queue<T>* queue, Node* ptrToNode) : m_queue(queue), m_ptrToNode(ptrToNode){
        }


/** opertator* of Iterator */
template <class T>
T& Queue<T>::Iterator::operator*() const {
    return m_ptrToNode->m_data;
}

/** opertator++ of Iterator */
template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
    if (m_ptrToNode == nullptr){
        throw InvalidOperation();
    }
    m_ptrToNode = m_ptrToNode->m_next;
    return *this;
}
/** opertator!= of Iterator */
template <class T>
bool Queue<T>::Iterator::operator!=(const Queue<T>::Iterator& iterator) {
    return (this->m_ptrToNode != iterator.m_ptrToNode);
}





/** constIterator impleciation */
template<class T>
class Queue<T>::ConstIterator {
private:
        const Queue<T>* m_queue;
        const Node*  m_ptrToNode ;
        ConstIterator(const Queue<T>* queue, Node* const ptrToNode);
        friend class Queue<T>::Node;
        friend class Queue<T>;
public:
        const T& operator*() const;
        ConstIterator& operator++();
        bool operator!=(const Queue<T>::ConstIterator& iterator);
        class InvalidOperation{};
};

/** constructor of ConstIterator */
template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, Node* const ptrToNode) : m_queue(queue), m_ptrToNode(ptrToNode){
}

/** opertator* of ConstIterator */
template <class T>
const T& Queue<T>::ConstIterator:: operator*() const {
    return m_ptrToNode->m_data;
}

/** opertator++ of ConstIterator */
template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++(){
    if (m_ptrToNode == nullptr){
        throw InvalidOperation();
    }
    m_ptrToNode = m_ptrToNode->m_next;
    return *this;
}

/** opertator!= of ConstIterator */
template <class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator& iterator) {
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
