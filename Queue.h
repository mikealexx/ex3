#ifndef QUEUE_H
#define QUEUE_H

//=========================================== Queue Declerations ===========================================

template<class T>
class Queue {

    class Node;

    Node* m_tail;

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
    Queue(Queue<T> &other);

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
    T front();

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
    int size();

    template <class Condition>
    Queue<T> filter(Condition cond);

    //void transform();

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
class Queue<T>::Node {

public:
    T m_data;
    Node* m_next;

    Node();

    Node(T data);

    Node& operator*();

};

//=========================================== Iterator Declerations ===========================================

template<class T>
class Queue<T>::Iterator {

    Node* m_node;

    Iterator(Node* node):
        m_node(node)
    {}

    friend class Queue<T>;

public:
    Iterator operator++() {
        if(this->m_node == nullptr) {
            throw Queue<T>::Iterator::InvalidOperation();
        }
        this->m_node = this->m_node->m_next;
        return *this;
    }

    bool operator!=(Iterator other) {
        return this->m_node != other.m_node;
    }

    T& operator*() {
        return this->m_node->m_data;
    }

    class InvalidOperation {};

};

//=========================================== ConstIterator Declerations ===========================================

template<class T>
class Queue<T>::ConstIterator {

    Node* m_node;

    ConstIterator(Node* node):
        m_node(node)
    {}

    friend class Queue<T>;

public:
    ConstIterator operator++() {
        if(this->m_node == nullptr) {
            throw Queue<T>::ConstIterator::InvalidOperation();
        }
        this->m_node = this->m_node->m_next;
        return *this;
    }

    bool operator!=(ConstIterator other) {
        return this->m_node != other.m_node;
    }

    T& operator*() {
        return this->m_node->m_data;
    }

    class InvalidOperation {};

};

//=========================================== Queue Definitions ===========================================

template<class T>
Queue<T>::Queue(): m_tail(nullptr), m_size(0) {}

template<class T>
Queue<T>::Queue(Queue<T> &other): m_tail(nullptr), m_size(0){
    for(Queue<T>::Iterator it = other.begin(); it != other.end(); ++it) {
        this->pushBack(*it);
    }
}

template<class T>
Queue<T>::~Queue() {
    while(this->m_size > 0) {
        this->popFront();
    }
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue<T> &other) {
    for(Queue<T>::Iterator it = this->begin(); it != this->end(); ++it) {
        this->popFront();
    }
    for(Queue<T>::Iterator it = other.begin(); it != other.end(); ++it) {
        this->pushBack(*it);
    }
    return *this;
}

template<class T>
void Queue<T>::pushBack(const T data) {
    Node* newNode = new Node(data);
    if(this->m_size == 0) {
        this->m_tail = newNode;
        this->m_size++;
        return;
    }
    newNode->m_next = this->m_tail;
    this->m_tail = newNode;
    this->m_size++;
}

template<class T>
T Queue<T>::front() {
    Node* ptr = this->m_tail;
    while (ptr->m_next != NULL) {
        ptr = ptr->m_next;
    }
    return ptr->m_data;
}

template<class T>
void Queue<T>::popFront() {
    if(this->m_size == 0) {
        throw Queue<T>::EmptyQueue();
    }
    Node* ptr = this->m_tail;
    if(ptr->m_next == NULL) {
        this->m_tail = nullptr;
        delete(ptr);
        this->m_size--;
        return;
    }
    while (ptr->m_next->m_next != NULL) {
        ptr = ptr->m_next;
    }
    delete(ptr->m_next);
    ptr->m_next = NULL;
    this->m_size--;
}

template<class T>
int Queue<T>::size() {
    return this->m_size;
}

template<class T, class Condition>
Queue<T> filter(Condition cond) {
    return Queue<T>();
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    if(this->m_tail == nullptr) {
        throw Queue<T>::EmptyQueue();
    }
    return Iterator(this->m_tail);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    if(this->m_tail == nullptr) {
        throw Queue<T>::EmptyQueue();
    }
    return ConstIterator(this->m_tail);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() {
    if(this->m_tail == nullptr) {
        throw Queue<T>::EmptyQueue();
    }
    Node* node = this->m_tail;
    while(node->m_next != NULL) {
        node = node->m_next;
    }
    return Iterator(node->m_next);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    if(this->m_tail == nullptr) {
        throw Queue<T>::EmptyQueue();
    }
    Node* node = this->m_tail;
    while(node->m_next != NULL) {
        node = node->m_next;
    }
    return ConstIterator(node->m_next);
}

//=========================================== Node Definitions ===========================================

template<class T>
Queue<T>::Node::Node():
    m_data()
{
    this->m_next = NULL;
}

template<class T>
Queue<T>::Node::Node(T data): m_data(data) {
    this->m_next = NULL;
}

template<class T>
typename Queue<T>::Node& Queue<T>::Node::operator*() {
    return this;
}

#endif //QUEUE_H