#pragma once
#include<iostream>
#include "Question.h"
#include "DoublyLinkedList.h"
#include <cstring>

class ManagerQuestion
{
    private:
        DoublyLinkedList<Question> list;
    public:
        Node <Question> *getList();
        void AddTail(Question &);
        void Show();
        int size();
        int Search(Question &);
        void ListNew(DoublyLinkedList<Question> &);
        Question &operator[](const int &);
};