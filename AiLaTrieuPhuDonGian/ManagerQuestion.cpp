#include "ManagerQuestion.h"

void ManagerQuestion::AddTail(Question &Q)
{
    list.AddTail(Q);
}

void ManagerQuestion::Show()
{
    Node<Question> *temp = list.getHead();
    while(temp != NULL)
    {
        temp->data.Show();
        temp = temp->next;
    }
}
int ManagerQuestion::size()
{
    return list.Size();
}

Question &ManagerQuestion::operator[](const int &index)
{
    return list[index];
}

Node<Question> *ManagerQuestion::getList()
{
    return list.getHead();
}

void ManagerQuestion::ListNew(DoublyLinkedList<Question> &ListNew)
{
    Node<Question> *temp = list.getHead();
    while(temp != NULL)
    {
        if(temp->data.getcheck() == true)
        {
           // Question t = temp->data;
            ListNew.AddTail(temp->data);
        }
        temp = temp->next;
    }
}

int ManagerQuestion::Search(Question &Q)
{
    int index = -1;
    Node<Question> *temp = list.getHead();
    if(temp == NULL)
        return -1;
    while(temp != NULL)
    {
        ++index;
        if(temp->data == Q)
        {
            return index;
        }
        temp = temp->next;
    }
    return -1;
}