//
// Created by eladm on 21/05/2022.
//

#ifndef HW3_LIST_H
#define HW3_LIST_H
template<class T>
class List{
public:
  explicit  List(T data);
    ~List()=default;
    List (const List& list ) =delete;
private:
    T m_data;
    List *m_next;
};
template<class T>
List<T>::List(T data):m_data(data){
    m_next=nullptr;
}
#endif //HW3_LIST_H
