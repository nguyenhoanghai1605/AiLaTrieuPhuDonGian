#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <assert.h>
using namespace std;

// Node
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;
    Node(T);
};

template <class T>
Node<T>::Node(T value)
{
    this->data = value;
    this->next = this->prev = NULL;
}

// List
template <class T>
class DoublyLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T> &);
    ~DoublyLinkedList();
    void AddHead(const T &);
    void AddTail(const T &);
    void InsertBeforeNode(Node<T> *, const T &);
    void InsertAfterNode(Node<T> *, const T &);
    void Insert(const T &, int);
    void RemoveHead();
    void RemoveTail();
    void RemoveNode(T);
    void Clear();
    bool isEmpty();
    void Show();
    void ShowReverse();
    int Size() const;
    Node<T> *getHead();
    Node<T> *getTail();
    int Search(const T &);
    Node<T> *SearchNode(const T &);
    T &operator[](const int &);
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = this->tail = NULL;
    this->size = 0;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &listCopy)
{
    this->head = listCopy.head;
    this->tail = listCopy.tail;
    this->size = listCopy.size;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Clear();
}

template <class T>
void DoublyLinkedList<T>::AddHead(const T &value)
{
    Node<T> *temp = new Node<T>(value);

    if (this->head == NULL)
        this->head = this->tail = temp;

    else
    {
        this->head->prev = temp;
        temp->next = this->head;
        this->head = temp;
    }
    this->size++;
}

template <class T>
void DoublyLinkedList<T>::AddTail(const T &value)
{
    Node<T> *temp = new Node<T>(value);

    if (this->tail == NULL)
        this->head = this->tail = temp;
    else
    {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    this->size++;
}

template <class T>
void DoublyLinkedList<T>::InsertBeforeNode(Node<T> *nextNode, const T &value)
{
    if (nextNode == NULL)
    {
        return;
    }

    Node<T> *new_node = new Node<T>(value);

    new_node->prev = nextNode->prev;
    nextNode->prev = new_node;
    new_node->next = nextNode;

    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    this->size++;
}

template <class T>
void DoublyLinkedList<T>::InsertAfterNode(Node<T> *prevNode, const T &value)
{
    if (prevNode == NULL)
    {
        return;
    }

    Node<T> *new_node = new Node<T>(value);

    new_node->next = prevNode->next;
    prevNode->next = new_node;
    new_node->prev = prevNode;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    this->size++;
}

template <class T>
void DoublyLinkedList<T>::Insert(const T &value, int index)
{
    if (index <= 0)
    {
        AddHead(value);
        return;
    }
    if (index >= this->size - 1)
    {
        AddTail(value);
        return;
    }
    Node<T> *temp = this->head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    InsertBeforeNode(temp, value);
}

template <class T>
void DoublyLinkedList<T>::RemoveHead()
{
    if (this->head == NULL)
    {
        return;
    }
    else
    {
        if (this->head == this->tail)
        {
            this->tail = this->head = NULL;
        }
        else
        {
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = NULL;
        }
        this->size--;
    }
}

template <class T>
void DoublyLinkedList<T>::RemoveTail()
{
    if (this->head == NULL)
    {
        return;
    }

    if (this->head == this->tail)
    {
        this->tail = this->head = NULL;
    }
    else
    {
        this->tail = this->tail->prev;
        delete this->tail->next;
        this->tail->next = NULL;
    }
    this->size--;
}

template <class T>
void DoublyLinkedList<T>::RemoveNode(T value)
{
    Node<T> *node = SearchNode(value);

    if (this->head == NULL || node == NULL)
    {
        return;
    }
    if (this->head == node)
    {
        RemoveHead();
        return;
    }
    if (this->tail == node)
    {
        RemoveTail();
        return;
    }

    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    node->prev = node->next = NULL;
    this->size--;
}

template <class T>
void DoublyLinkedList<T>::Clear()
{
    while (this->head != NULL)
    {
        RemoveHead();
    }
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
    return this->size < 1 ? true : false;
}

template <class T>
void DoublyLinkedList<T>::Show()
{
    Node<T> *temp = this->head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

template <class T>
void DoublyLinkedList<T>::ShowReverse()
{
    Node<T> *temp = this->tail;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->prev;
    }
}

template <class T>
int DoublyLinkedList<T>::Size() const
{
    return this->size;
}

template <class T>
Node<T> *DoublyLinkedList<T>::getHead()
{
    return this->head;
}

template <class T>
Node<T> *DoublyLinkedList<T>::getTail()
{
    return this->tail;
}

template <class T>
int DoublyLinkedList<T>::Search(const T &value)
{
    int index = -1;
    if (this->head != NULL)
    {
        Node<T> *temp = this->head;
        while (temp)
        {
            index++;
            if (temp->data == value)
            {
                return index;
            }
            temp = temp->next;
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
    return -1;
}

template <class T>
Node<T> *DoublyLinkedList<T>::SearchNode(const T &value)
{
    Node<T> *temp = this->head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp != NULL)
        return temp;
    return NULL;
}

template <class T>
T &DoublyLinkedList<T>::operator[](const int &index)
{
    assert(index >= 0 && index < this->size);

    if (index == this->size - 1)
        return this->tail->data;

    Node<T> *temp = this->head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

#endif
