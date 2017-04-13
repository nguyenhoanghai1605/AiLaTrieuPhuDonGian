#include "Menu.h"


int main()
{
    ManagerQuestion data;
    ManagerPlayer dataP;
    ifstream filein;
    ofstream fileout;
    DataTxt(data, filein); 
    DataPTxt(dataP, filein);

    system("cls");
    LoadingGame();
    Player P;

    SetColor(0, 2); // cái này in màu
    SetConsoleOutputCP(65001); // cái này in ra kiểu chữ tiếng việt

    SelectMenu(data, dataP, fileout);



}
