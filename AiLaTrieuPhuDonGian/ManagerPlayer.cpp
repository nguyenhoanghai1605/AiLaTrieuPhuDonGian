#include "ManagerPlayer.h"

void ManagerPlayer::AddTail(Player &P)
{
    list.AddTail(P);
}

void ManagerPlayer::Sort()
{
    for(Node<Player> *temp = list.getHead(); temp != NULL; temp = temp->next)
    {
        for(Node<Player> *t = temp->next; t != NULL; t = t->next)
        {
            if(t->data.getScore() > temp->data.getScore())
            {
                Player P = t->data;
                t->data = temp->data;
                temp->data = P; 
            }
        }
    }
}
void ManagerPlayer::Show()
{
    Node<Player> *temp = list.getHead();
    int i = 0;
    while(temp != NULL)
    {
        cout << setw(5) << left << i+1;
        temp->data.Show();
        temp = temp->next;
        i++;
    }
}

Node<Player> *ManagerPlayer::getList()
{
    return list.getHead();
}

void ManagerPlayer::DeleteTail()
{
    list.RemoveTail();
}