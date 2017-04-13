#include "Player.h"

Player::Player()
{
    
}
Player::~Player()
{

}

string Player::getName()
{
    return name;
}

string Player::getPrize()
{
    return prize;
}

int Player::getScore()
{
    return score;
}
void Player::setScore(int &score)
{
    this->score = score;
}

void Player::setPrize(string &p)
{
    prize = p;
}
void Player::setName(string &name)
{
    this->name = name;
}

istream& operator>>(istream &is, Player &P)
{
    fflush(stdin);
    getline(is, P.name);
    return is;
}
ostream& operator<<(ostream &os, const Player &P)
{
    os << P.name << P.score << endl;
    return os;
}

void Player::getDataPlayer(ifstream &file)
{
    fflush(stdin);
    getline(file >> ws, name, ',');
    getline(file >> ws, prize, ',');
    file >> ws >> score;
    fflush(stdin);
}

