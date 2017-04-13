#include "DoublyLinkedList.h"
#include "Player.h"
class ManagerPlayer
{
    private:
        DoublyLinkedList<Player> list;
    public:
        void AddTail(Player &);
        void DeleteTail();
        void Sort();
        void Show();
        Node<Player> *getList();
};