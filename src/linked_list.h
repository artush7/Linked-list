#include <stdexcept>
#include <iterator>
#include <cstddef>
#include <functional>
#include <algorithm>
#include <iostream>

template <typename T>
class linked_list
{

private:
    class Node
    {
    public:
        Node* next_address;
        T data;

        Node(T data);
    };

    Node* head;
    
public:

    class Iterator
    { 
    private:
        Node* head_it;
    public:
        using difference_type = std::ptrdiff_t;
        using value_type = std::remove_cv_t<T>;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::forward_iterator_tag;
        using iterator_concept = std::forward_iterator_tag;

        Iterator(Node* head);
        T& operator*() const;
        Iterator operator++(int);
        Iterator operator++();
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;

    };
    
    linked_list();
    
    void insert_head(T value);  
    void insert(int position, T value);
    void insert_tail(T value);
    T get(int position);
    void remove(int position);
    void ForEach(std::function<void(T&)>);

    linked_list(const linked_list<T>& other);
    linked_list<T>& operator=(const linked_list<T>& other);
    linked_list(linked_list<T>&& other);
    linked_list<T>& operator=(linked_list<T>&& other);
    ~linked_list();

    Iterator begin();
    Iterator end();


};


template <typename T>
linked_list<T>::linked_list()
{
    head = nullptr;
}

template <typename T>
void linked_list<T>::insert_head(T value)
{
    Node* new_node = new Node(value);
    new_node->next_address = head;
    head = new_node;
}

template <typename T>
void linked_list<T>::insert(int position, T value)
{
    if (position == 0)
    {
        insert_head(value);
        return;
    }

    Node* current = head;
    for(int i = 0;i < position - 1;++i)
    {   
        if (current == nullptr)
        {
            throw std::out_of_range("Position is out of range in insert()");
        }
         
        current = current->next_address;
    }

    if (current == nullptr) 
    {
        throw std::out_of_range("position out of range (after loop) in insert()");
    }

    Node* new_node = new Node(value);
    new_node->next_address = current->next_address;
    current->next_address = new_node;
}

template <typename T>
void linked_list<T>::insert_tail(T value)
{
    Node* new_node = new Node(value);

    if(head == nullptr)
    {
        head = new_node;
        return;
    }


    Node* current = head;

    while (current->next_address != nullptr)
    {
        current = current->next_address;
    }

    current->next_address = new_node;
}

template <typename T>
T linked_list<T>::get(int position)
{
    Node* current = head;
    for (int i = 0; i < position; ++i)
    {
        if (current == nullptr)
        {
            throw std::out_of_range("Position is out of range in get()");
        }
        current = current->next_address;
    }
    if (current == nullptr)
    {
        throw std::out_of_range("position out of range (after loop) in get()");
    }
    return current->data;
}

template <typename T>
void linked_list<T>::remove(int position)
{
    if (position == 0)
    {
        if (head == nullptr)
            throw std::out_of_range("Cannot remove empty list");
        
        Node* temporary_head = head;
        head = head->next_address;
        delete temporary_head;
        return;
    }

    Node* current = head;
    for (int i = 0;i < position - 1; ++i)
    {
        if (current == nullptr) 
            throw std::out_of_range("Position is out of range in remove()");

        current = current->next_address;
    }

    if (current == nullptr) 
        throw std::out_of_range("position out of range (after loop) in remove()");

    Node* temporary_node = current->next_address;

    if (temporary_node == nullptr) 
        throw std::out_of_range("cannot remove:position is beyond list size");

    current->next_address = temporary_node->next_address;
    delete temporary_node;
}

template <typename T>
linked_list<T>::~linked_list() 
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next_address;
        delete current;
        current = next;
    }
    head = nullptr;
}

template <typename T>
linked_list<T>::linked_list(const linked_list<T>& other)
{
    if(other.head == nullptr)
    {
        head = nullptr;
        return;
    }

    this->head = new Node(other.head->data);

    Node* next_other = other.head->next_address;
    Node* this_head = head;

    while (next_other != nullptr)
    {
        this_head->next_address = new Node(next_other->data);
        this_head = this_head->next_address;
        next_other = next_other->next_address;
    }

}

template <typename T>
linked_list<T>& linked_list<T>::operator=(const linked_list<T>& other)
{
    if(this == &other)
    {
        return *this;
    }

    linked_list<T> tmp(other);

    std::swap(this->head,tmp.head);

    return *this;
}

template <typename T>
linked_list<T>::linked_list(linked_list<T>&& other)
{
    this->head = other.head;
    other.head = nullptr;
    
}

template <typename T>
linked_list<T>& linked_list<T>::operator=(linked_list<T>&& other)
{
    if(this == &other)
    {
        return *this;
    }
    
    std::swap(other.head,this->head);

    return *this;
}

template <typename T>
void linked_list<T>::ForEach(std::function<void(T&)> some_func)
{
    Node* current = head;
    while (current != nullptr)
    {
        some_func(current->data);
        current = current->next_address;
    }
}

template <typename T>
linked_list<T>::Node::Node(T data)
{
    this->next_address = nullptr;
    this->data = data;
}

template <typename T>
linked_list<T>::Iterator::Iterator(Node* head)
{      
    head_it = head;
}

template <typename T>
T& linked_list<T>::Iterator::operator*() const
{   
    if (head_it == nullptr)
        throw std::logic_error("cannot dereference end()");
    return head_it->data;
}


template <typename T>
typename linked_list<T>::Iterator linked_list<T>::begin()
{
    return Iterator(head);
}

template <typename T>
typename linked_list<T>::Iterator linked_list<T>::Iterator::operator++(int)
{
    if (head_it == nullptr)
        throw std::logic_error("cannot increment end()");
    head_it = head_it->next_address;
    return *this;
}

template <typename T>
typename linked_list<T>::Iterator linked_list<T>::end()
{   
    return Iterator(nullptr);
}

template <typename T>
bool linked_list<T>::Iterator::operator!=(const Iterator& other) const
{
    return head_it != other.head_it;
}

template <typename T>
bool linked_list<T>::Iterator::operator==(const Iterator& other) const
{
    return head_it == other.head_it;
}

template <typename T>
typename linked_list<T>::Iterator linked_list<T>::Iterator::operator++()
{
    if (head_it == nullptr)
        throw std::logic_error("cannot increment end()");
    head_it = head_it->next_address;
    return *this;
}

