
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
    Queue();
    Queue(const Queue<T>& queue);
    ~Queue();

    class Iterator;
    class ConstIterator;

    class EmptyQueue{};
    Queue<T>::Node* getHead(){
        return m_head;
    }

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
template<class T>
Queue<T>::Queue(const Queue<T> &queue) :m_size(0), m_head(nullptr){
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
    Queue<T>::Node *newHead = nullptr;
    try {
        for (const T &data: queue) {
            Queue<T>::Node *tempNode = new Queue<T>::Node(data);
            if (newHead == nullptr) {
                newHead = tempNode;
                continue;
            }
            Queue<T>::Node *temp = newHead;
            while (temp->m_next != nullptr) {
                temp = temp->m_next;
            }
            temp->m_next = tempNode;
        }
    } catch (std::bad_alloc){
        while (newHead != nullptr){
            Node* toDelete = newHead;
            newHead = newHead->m_next;
            delete toDelete;
        }
        return *this;
    }
    while(this->m_head!= nullptr) {                   //if we got here, then copying worked! we can safely delete data from old queue
        Node *toDelete = this->m_head;
        this->m_head = this->m_head->m_next;
        delete toDelete;
    }
    this->m_head = newHead;
    this->m_size = queue.size();
    return *this;

}


/**---pushBack method---
 *
 *
 * the function creating new node initialized with the data T and - and linked to the last node
 *
 *
 * @tparam T - the data type
 * @param objectToPush - the object to push to the end of the Queue (type T)
 */
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
        while(this->m_head!= nullptr) {
            Node* toDelete = this->m_head;
            this->m_head = this->m_head->m_next;
            delete toDelete;
        }
        throw std::bad_alloc();
    }
}


/**---front method----
 *
 *
 * @tparam T the data type
 * @return the first object (type T) in the Queue
 */
template<class T>
T& Queue<T>::front() const{
    if (this->m_size == 0){
        throw EmptyQueue();
    }
    return this->m_head->m_data;
}


/**---popFront method---
 *
 * delete the first object (type T) in the Queue
 * (checks for empty Queue)
 *
 * @tparam T - data type
 */
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

/**---size method---
 *
 *
 * @tparam T - data type
 * @return number of objects (type T) in the Queue
 */
template<class T>
int Queue<T>::size() const{
    return this->m_size;
}


/***------------Queue begin--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::begin()  {
    Iterator it( this->m_head);
    return it;
}
/***------------Queue end--------------***/
template<class T>
typename Queue<T>::Iterator Queue<T>::end()  {
    return Iterator(nullptr);
}

/***------------Queue begin const--------------***/
template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const  {
    ConstIterator it(this->m_head);
    return it;
}
/***------------Queue end const--------------***/
template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const  {
    return ConstIterator(nullptr);
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
/**-- filter function ---
 *
 * filter function create a new Queue and returns it containing copy of the
 * objects passed the condition
 *
 * @tparam T  - data type
 * @tparam Condition - bool functor/ function ptr type
 * @param queue - the Queue that will filtered (not changed)
 * @param condition  the functor/ function ptr Queue will be filtered by
 * @return a new Queue contains only the objects (type T) that condition returned true for
 */
template<class T, class Condition>
Queue<T> filter(const Queue<T> &queue ,const Condition condition)
{
    Queue<T> newQueue;
    try {
        for (const T& data: queue) {
            if (condition(data) == true) {
                newQueue.pushBack(data);
            }
        }
    } catch (std::bad_alloc& e){
    }
    return newQueue;

}
/**--- transform function --
 *
 *
 * * transform function returns the Queue received after it changed by operation
 *
 *
 * @tparam T - data type
 * @tparam Operation  functor/ function ptr type
 * @param queue the Queue that will transformed
 * @param operation the functor/ function ptr that Queue will be transformed by
 */
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
    //const Queue<T>* m_queue;
    Node* m_ptrToNode;
    explicit Iterator(Node* ptrToNode);
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
Queue<T>::Iterator::Iterator(Node* ptrToNode) : m_ptrToNode(ptrToNode){
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
        //const Queue<T>* m_queue;
        Node*  m_ptrToNode ;
        explicit ConstIterator(Node* const ptrToNode);
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
Queue<T>::ConstIterator::ConstIterator(Node* const ptrToNode) :m_ptrToNode(ptrToNode){
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
