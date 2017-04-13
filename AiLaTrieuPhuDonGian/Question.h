#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;
class Question
{
    private:
        string question;
        string A;
        string B;
        string C;
        string D;
        string result;
        bool check;
    public:
        Question();
        ~Question();
        string getQuestion();
        string getA();
        string getB();
        string getC();
        string getD();
        string getResult();
        void setCheck(bool check)
        {
            this->check = check;
        }
        bool getcheck();
        friend istream& operator>>(istream &, Question &);
        friend ostream& operator<<(ostream &, const Question &);
        void getDataQuestion(ifstream &);
        void Show();
        friend bool operator==(const Question &, const Question &);
        
};