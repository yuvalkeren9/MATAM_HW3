//
// Created by eladm on 21/05/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
template<class T>
class Queue {
private:
    class List;
    Queue<T>::List  *m_head;
    int m_size;

public:
    Queue();
    ~Queue()=default;
    Queue(Queue& queue)=delete;
    void pushBack(T objectToPush);
    T& front() const;
    void popFront();
    int size() const;
    Queue<T>::List* getLastNode() const;

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

};
/***------------Queue methods--------------***/
template<class T>
Queue<T>::Queue():m_head(nullptr),m_size(0) {}

/*
template<class T>
void Queue<T>::pushBack(T objectToPush) {                   //old
    Queue<T>::List node(objectToPush);
    Queue<T>::List* temp= this->getLastNode();
    *temp->m_next= node;
    this->m_size++;
}
*/

template<class T>
void Queue<T>::pushBack(T objectToPush) {                   //allocate dymnic ?
    Queue<T>::List* node = new Queue<T>::List(objectToPush);
    Queue<T>::List *currentLastNode = this->getLastNode();
    *currentLastNode->m_next = node;
    this->m_size++;
}

template<class T>
T& Queue<T>::front() const{
    if(this->m_size==0)
        return nullptr ;//check in piazza
    return this->m_head->m_next->m_data;
}

template<class T>
void Queue<T>::popFront(){
    if(this->m_size!=0){
        Queue<T>::List temp= this->m_head->m_next;
        this->m_head = temp.m_next;
        delete temp;
        this->m_size--;
    }
}

template<class T>
int Queue<T>::size() const{
    return this->m_size;
}

/***------------Queue global functions--------------***/
template<class T,class C>
        Queue<T> filter(Queue<T> queue ,C condition)
{
            Queue<T> newQueue;

}


/***-----------Iterator implication------------***/
template<class T>
class Queue<T>::Iterator{
private:
    Iterator(const Queue<T>* queue, int index);
    const Queue<T>* queue;
    T* ptrToNode;
public:

};




/***-----------list implication------------***/
template<class T>
class Queue<T>::List{
public:
    ~List()=default;
    List (const List& list ) = delete;
private:
    T m_data;
    List *m_next;
    explicit List(T data);
    friend class Queue<T>;
};
template<class T>
Queue<T>::List::List(T data):m_data(data){
    m_next=nullptr;
}






/**---------------helper function-------------**/
template<class T>
typename Queue<T>::List* Queue<T>::getLastNode() const{//check for typename
    Queue<T>::List * temp= this->m_head;
    while (temp!= nullptr)
    {
        temp=temp->m_next;
    }
    return temp;
}


#endif //HW3_QUEUE_H
