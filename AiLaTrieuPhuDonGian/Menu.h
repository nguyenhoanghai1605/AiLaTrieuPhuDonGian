#include "ManagerQuestion.h"
#include "ManagerPlayer.h"
#include <windows.h>
#include <cstring>

void LoadingGame();
void MenuGame(); // Giao dien
void DataTxt(ManagerQuestion &, ifstream &);// Doc du lieu
void DataPTxt(ManagerPlayer &, ifstream &);
void DataOut(ManagerPlayer &, ofstream &);

int Select();
void RandomQuestion(ManagerQuestion &, ManagerPlayer &);
void RandomAnswer(Question &, string A[]);
string SearchAnswer(Question &, string A[]);
void SelectMenu(ManagerQuestion &, ManagerPlayer &, ofstream &);
void Resetgame(ManagerQuestion &);
void SaveScore(ManagerPlayer &, int);

string TienThuong(int );
void MenuPlay(int);
void HelpCall(Question &, int, string A[]);
void TuVanTaiCho(Question &, int, string A[]);
void ThamKhaoYKienKhanGia(Question &, int, string A[]);
void LoaiBo50(Question &, int, string A[]);

string doi(int);

void SetColor(int backgound_color, int text_color);

/*
0 = Black         8 = Gray
1 = Blue          9 = Light Blue
2 = Green         10 = Light Green
3 = Aqua          11 = Light Aqua
4 = Red           12 = Light Red
5 = Purple        13 = Light Purple
6 = Yellow        14 = Light Yellow
7 = White         15 = Bright White
*/