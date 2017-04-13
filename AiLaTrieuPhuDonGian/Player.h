#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Player
{
    private: 
        string name;
        int score;
        string prize; 
    public:
        Player();
        ~Player();
        string getName();
        string getPrize();
        int getScore();
        void setScore(int &);
        void setName(string &);
        void setPrize(string &);
        void Show()
        {
            cout << setw(15) << left << name << setw(10) << left << prize << endl;
        }
        void getDataPlayer(ifstream &);
        friend istream& operator>>(istream &, Player &);
        friend ostream& operator<<(ostream &, const Player &);
};