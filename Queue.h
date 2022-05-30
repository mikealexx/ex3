#ifndef QUEUE_H
#define QUEUE_H


//=========================================== Queue Declerations ===========================================

template<class T>
class Queue
{

    class Node;

    Node* m_head;

    int m_size;

public:

    /**
     * @brief Construct a new queue
     * 
     */
    Queue();

    /**
     * @brief Construct a new copy of Queue
     * 
     * @param other The other queue to copy from
     */
    Queue(const Queue<T> &other);

    /**
     * @brief Destroy the Queue
     * 
     */
    ~Queue();

    /**
     * @brief Assign to this queue the data from another queue
     * 
     * @param other The other queue to copy from
     * @return Queue<T>& The updated queue
     */
    Queue<T>& operator=(Queue &other);

    Queue<T>& operator*();

    /**
     * @brief Add new data to the end of the queue
     * 
     * @param data The data to add to the queue
     */
    void pushBack(T data);

    /**
     * @brief Get the first data in queue without removing it
     * 
     * @return T The first data
     */
    T& front() const;

    /**
     * @brief Remove the first data in queue
     * 
     */
    void popFront();

    /**
     * @brief Get the size of the queue
     * 
     * @return int The size of the queue
     */
    int size() const;

    class Iterator;

    class ConstIterator;

    /**
     * @brief Set an iterator to the start of the queue
     * 
     * @return Iterator 
     */
    Iterator begin();
    ConstIterator begin() const;

    /**
     * @brief Set an iterator to the end of the queue
     * 
     * @return Iterator 
     */
    Iterator end();
    ConstIterator end() const;

    class EmptyQueue {};

};

//=========================================== Node Declerations ===========================================

template<class T>
class Queue<T>::Node
{

public:
    T m_data;
    Node* m_next;

    /**
     * @brief Construct a new Node
     * 
     */
    Node();

    /**
     * @brief Destroy the Node object
     * 
     */
    ~Node() = default;

    /**
     * @brief Construct a new copy of Node
     * 
     * @param data The data to copy from
     */
    Node(T data);

    /**
     * @brief Dereference operator
     * 
     * @return Node& Dereferenced node
     */
    Node& operator*();

};

//=========================================== Iterator Declerations ===========================================

template<class T>
class Queue<T>::Iterator
{

    Node* m_node;

    /**
     * @brief Construct a new Iterator pointing to a node
     * 
     * @param node The node to point to
     */
    Iterator(Node* node):
        m_node(node)
    {}

    friend class Queue<T>;

public:
    /**
     * @brief Update the iterator to point to the following node
     * 
     * @return Iterator The updated iterator
     */
    Iterator operator++()
    {
        if(this->m_node == nullptr) {
            throw Queue<T>::Iterator::InvalidOperation();
        }
        this->m_node = this->m_node->m_next;
        return *this;
    }

    /**
     * @brief Check whether two iterators point to different nodes
     * 
     * @param other The other iterator to compare to
     * @return true If the two iterators point to different nodes
     * @return false otherwise
     */
    bool operator!=(Iterator other)
    {
        return this->m_node != other.m_node;
    }

    /**
     * @brief Dereference the iterator AKA return the data it's pointing to
     * 
     * @return T& The data the iterator points to
     */
    T& operator*()
    {
        return this->m_node->m_data;
    }

    class InvalidOperation {};

};

//=========================================== ConstIterator Declerations ===========================================

template<class T>
class Queue<T>::ConstIterator
{

    Node* m_node;

    /**
     * @brief Construct a new ConstIterator pointing to a node
     * 
     * @param node The node to point to
     */
    ConstIterator(Node* node):
        m_node(node)
    {}

    friend class Queue<T>;

public:
    /**
     * @brief Update the const iterator to point to the following node
     * 
     * @return ConstIterator The updated const iterator
     */
    ConstIterator operator++()
    {
        if(this->m_node == nullptr) {
            throw Queue<T>::ConstIterator::InvalidOperation();
        }
        this->m_node = this->m_node->m_next;
        return *this;
    }

    /**
     * @brief Check whether two cosnt iterators point to different nodes
     * 
     * @param other The other const iterator to compare to
     * @return true If the two const iterators point to different nodes
     * @return false otherwise
     */
    bool operator!=(ConstIterator other)
    {
        return this->m_node != other.m_node;
    }

    /**
     * @brief Dereference the const iterator AKA return the data it's pointing to
     * 
     * @return T& The data the const iterator points to
     */
    T& operator*()
    {
        return this->m_node->m_data;
    }

    class InvalidOperation {};

};

//=========================================== Queue Implementations ===========================================

template<class T>
Queue<T>::Queue(): m_head(nullptr), m_size(0) {}

template<class T>
Queue<T>::Queue(const Queue<T> &other): m_head(nullptr), m_size(0)
{
    for(Queue<T>::ConstIterator it = other.begin(); it != other.end(); ++it) {
        this->pushBack(*it);
    }
}

template<class T>
Queue<T>::~Queue()
{
    while(this->m_size > 0) {
        this->popFront();
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue<T> &other)
{
    for(Queue<T>::Iterator it = this->begin(); it != this->end(); ++it) {
        this->popFront();
    }
    for(Queue<T>::Iterator it = other.begin(); it != other.end(); ++it) {
        this->pushBack(*it);
    }
    return *this;
}

template<class T>
Queue<T>& Queue<T>::operator*()
{
    return *this;
}

template<class T>
void Queue<T>::pushBack(const T data)
{
    Node* newNode = new Node(data);
    if(this->m_size == 0) {
        this->m_head = newNode;
        this->m_size++;
        return;
    }
    Node* ptr = this->m_head;
    while(ptr->m_next != nullptr) {
        ptr = ptr->m_next;
    }
    ptr->m_next = newNode;
    this->m_size++;
}

template<class T>
T& Queue<T>::front() const
{
    if(this->m_size == 0) {
        throw Queue<T>::EmptyQueue();
    }
    return this->m_head->m_data;
}

template<class T>
void Queue<T>::popFront()
{
    if(this->m_size == 0) {
        throw Queue<T>::EmptyQueue();
    }
    Node* toDelete = this->m_head;
    this->m_head = this->m_head->m_next;
    delete(toDelete);
    this->m_size--;
}

template<class T>
int Queue<T>::size() const
{
    return this->m_size;
}

template<class T, class Condition>
Queue<T> filter(const Queue<T> &q, Condition cond)
{
    Queue<T> newQueue;
    for(typename Queue<T>::ConstIterator i = q.begin(); i != q.end(); ++i) {
        if(cond(*i)) {
            newQueue.pushBack(*i);
        }
    }
    return newQueue;
}

template<class T, class Function>
void transform(const Queue<T> &q, Function func)
{
    for(typename Queue<T>::ConstIterator i = q.begin(); i != q.end(); ++i) {
        func(*i);
    }
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    if(this->m_head == nullptr) {
        throw Queue<T>::EmptyQueue();
    }
    return Iterator(this->m_head);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    if(this->m_size == 0) {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(this->m_head);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(nullptr);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(nullptr);
}

//=========================================== Node Implementation ===========================================

template<class T>
Queue<T>::Node::Node():
    m_data()
{
    this->m_next = nullptr;
}

template<class T>
Queue<T>::Node::Node(T data): m_data(data)
{
    this->m_next = nullptr;
}

template<class T>
typename Queue<T>::Node& Queue<T>::Node::operator*()
{
    return this;
}

#endif //QUEUE_H