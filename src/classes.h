
template <typename T>
class Node
{
private:
    Node<T>* next_address;
    T data;
public:
    Node(T data);
};


template <typename T>
class linked_list
{
private:
    Node<T>* head;
public:
    linked_list();
    void insert_head(T value);  
};

