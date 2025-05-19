template <typename T>
class Node
{
protected:
public:
    Node<T>* next_address;
    T data;
    Node(T data);
};

template <typename T>
Node<T>::Node(T data)
{
    this->next_address = nullptr;
    this->data = data;
}