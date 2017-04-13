#include "Question.h"

Question::Question()
{

}

Question::~Question()
{

}

string Question::getA()
{
    return A;
}
string Question::getB()
{
    return B;
}
string Question::getC()
{
    return C;
}
string Question::getD()
{
    return D;
}
string Question::getQuestion()
{
    return question;
}
string Question::getResult()
{
    return result;
}
bool Question::getcheck()
{
    return check;
}
istream& operator>>(istream &is, Question &Q)
{
    is >> Q.question;
    is >> Q.A;
    is >> Q.B;
    is >> Q.C;
    is >> Q.D;
    is >> Q.result;
    return is;
}

ostream& operator<<(ostream &os, const Question &Q)
{
    bool check = true;
    for(int i = 0; i < Q.question.size(); i++)
    {
        if(i < 90)
        {
            cout <<Q.question[i];
        }
        else if(i >= 90 && i <180)
        {
            if(Q.question[i] == ' ' && check == true)
            {
                cout << endl;
                check = false;
            }
            else 
                cout << Q.question[i];
        }
        else 
        {
            if(Q.question[i] == ' ' && check == false)
            {
                cout << endl;
                check = true;
            }
            else 
                cout << Q.question[i];
        }
    }
    cout << endl;
    return os;
}

void Question::getDataQuestion(ifstream &file)
{
    fflush(stdin);
    getline(file >> ws, this->question, '/');
    fflush(stdin);
    getline(file >> ws, A, '|');
    fflush(stdin);
    getline(file >> ws, B, '|');
    fflush(stdin);
    getline(file >> ws, C, '|');
    fflush(stdin);
    getline(file >> ws, D, '|');
    fflush(stdin);
    getline(file >> ws, result);
    fflush(stdin);
}

void Question::Show()
{
    cout << question << endl;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    cout << D << endl;
    cout << result << endl << endl;
}

bool operator==(const Question &Q1, const Question &Q2)
{
    return(Q1.A == Q2.A && Q1.B == Q2.B && Q1.C == Q2.C && Q1.D == Q2.D && Q1.question == Q2.question ? true : false);
}