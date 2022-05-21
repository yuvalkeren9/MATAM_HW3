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

    Queue<T>::List* getLastNode() const;

};


/***list implication***/
template<class T>
class Queue<T>::List{
public:
    explicit List(T data);
    ~List()=default;
    List (const List& list ) =delete;
    T m_data;
    List *m_next;
};
template<class T>
Queue<T>::List::List(T data):m_data(data){
    m_next=nullptr;
}

/***Queue methods***/
template<class T>
Queue<T>::Queue():m_head(nullptr),m_size(0) {}

template<class T>
void Queue<T>::pushBack(T objectToPush) {
    Queue<T>::List node(objectToPush);
    Queue<T>::List* temp= this->getLastNode();
    *temp->m_next= node;
    this->m_size++;
}
template<class T>
typename Queue<T>::List* Queue<T>::getLastNode() const{//check for typename
    Queue<T>::List * temp= this->m_head;
    while (temp!= nullptr)
    {
        temp=temp->m_next;
    }
    return temp;
}
 int main(){
        Queue<int> queue;
        queue.pushBack(1);
        queue.pushBack(2);
        queue.getLastNode();

    };
#endif //HW3_QUEUE_H
