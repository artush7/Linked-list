#include "/home/artush/#main(linux)/c++ project/homework/Linked list/src/classes.h"

template <typename T>
linked_list<T>::linked_list()
{
    head = nullptr;
}

template <typename T>
Node<T>::Node(T data)
{
    this->next_address = nullptr;
    this->data = data;
}

template <typename T>
void linked_list<T>::insert_head(T value)
{
    Node<T>* new_node = new Node<T>(value);
    new_node->next_address = head;
    head = new_node;
}