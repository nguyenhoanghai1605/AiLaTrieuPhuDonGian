#include "Menu.h"


bool CheckHeplCall = true;
bool CheckTuVanTaiCho = true;
bool CheckThamKhaoYKienKhanGia = true;
bool CheckLoaiBo50 = true;
string CauChon;
int ViTriCauChon = 0;

void LoadingGame()
{
    SetColor(0, 6);
    cout << "\n\n\n\n\t\t\t    LOADING GAME\n\t\t";
    for(int i = 0; i < 40; i++)
    {
        cout << "|";
        Sleep(10);
    }
}

void MenuGame()
{
    cout << endl;
    cout << "\n\n\n\t\t=================MENU==============" << endl
         << "\t\t|  1. Trò Chơi Mới                |" << endl
         << "\t\t|  2. Xếp Hạng                    |" << endl
         << "\t\t|  0. Thoát!!!                    |" << endl
         << "\t\t===================================" << endl;
}

void DataTxt(ManagerQuestion &data, ifstream &filein)
{
    filein.open("data.txt", ios_base::in);
    if (!filein)
    {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    Question temp;
    while (!filein.eof())
    {
        temp.getDataQuestion(filein);
        data.AddTail(temp);
    }
    filein.close();
}

void DataPTxt(ManagerPlayer &data, ifstream &filein)
{
    filein.open("dataPlayer.txt");
    if (!filein)
    {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    Player temp;
    while (!filein.eof())
    {
        temp.getDataPlayer(filein);
        data.AddTail(temp);
    }
    data.DeleteTail();
    filein.close();
}

void DataOut(ManagerPlayer &data, ofstream &fileout)
{
    fileout.open("dataPlayer.txt", ios::out);
    Node<Player> *temp = data.getList();
    while(temp != NULL)
    {
        fileout << temp->data.getName() << ", " << temp->data.getPrize() << ", " << temp->data.getScore() << endl;
        temp = temp->next;
    }
    fileout.close();
}

void ResetGame(ManagerQuestion &data)
{
    Node<Question> *temp = data.getList();
    while(temp != NULL)
    {
        temp->data.setCheck(true);
        temp = temp->next;
    }

    CheckHeplCall = true;
    CheckTuVanTaiCho = true;
    CheckThamKhaoYKienKhanGia = true;
    CheckLoaiBo50 = true;
    CauChon = "";
    ViTriCauChon = 0;
}

void RandomQuestion(ManagerQuestion &data, ManagerPlayer &dataP)
{
    int size = 0;
    string dapan;
    DoublyLinkedList<Question> dataNew;// danh sach cau hoi
    data.ListNew(dataNew);  // lay danh sach cau hoi
    string A[4];

    while(size < 15) // choi
    {   
        system("cls");
        srand(time(NULL));
        int chose = rand()%dataNew.Size(); // Chọn câu hỏi ngẫu nhiên
        Question Q = dataNew[chose];// Câu chọn

        RandomAnswer(Q, A);
        MenuPlay(size);

        cout << "\nCâu " << size + 1 << ": ";
        cout << Q << endl;
        cout << "A." << setw(40) << left << A[0] << "B." << setw(40) << left << A[1] << endl;
        cout << "C." << setw(40) << left << A[2] << "D." << setw(40) << left << A[3] << endl;
        cout << "---------------------------------------------------------------" << endl;


        cout << "\nĐáp Án Bạn chọn(A/B/C/D hoặc 1/2/3/4 để sử dụng trợ giúp): ";
        fflush(stdin);
        cin >> dapan;
        // Tro Giup
        while(dapan == "1" || dapan == "2" || dapan == "3" || dapan == "4")
        {
            if(dapan == "1")
            {
                if(CheckHeplCall == true)
                {
                    cout << "\nGọi điện thoại:\n";
                    HelpCall(Q, size + 1, A);
                    CheckHeplCall = false;
                }
                else 
                    cout << "Bạn đã sử dụng sự trợ giúp này trước đó!" << endl;
            }
            if(dapan == "2")
            {
                if(CheckTuVanTaiCho)
                {
                    cout <<"\nTư vấn tại chỗ\n";
                    TuVanTaiCho(Q, size + 1, A);
                    CheckTuVanTaiCho = false;
                }
                else
                    cout << "Bạn đã sử dụng sự trợ giúp này trước đó!" << endl;
            }
            if(dapan == "3")
            {
                if(CheckThamKhaoYKienKhanGia)
                {
                    cout << "\nTham khảo ý kiến khảo giả\n";
                    ThamKhaoYKienKhanGia(Q, size + 1, A);
                    CheckThamKhaoYKienKhanGia = false;
                }
                else
                    cout << "Bạn đã sử dụng sự trợ giúp này trước đó!" << endl;
            }
            if(dapan == "4")
            {
                if(CheckLoaiBo50)
                {
                	CheckLoaiBo50 = false;
                    system("cls");
                    LoaiBo50(Q, size + 1, A);
                }
                else
                    cout << "Bạn đã sử dụng sự trợ giúp này trước đó!" << endl;
            }
            cout << "\nĐáp Án Bạn chọn hoặc (1/2/3/4 để trợ giúp): ";
            fflush(stdin);
            cin >> dapan;
        }

        string DapAn;
        if(dapan == "A" || dapan == "a")   DapAn = A[0];
        if(dapan == "B" || dapan == "b")   DapAn = A[1];
        if(dapan == "C" || dapan == "c")   DapAn = A[2];
        if(dapan == "D" || dapan == "d")   DapAn = A[3];

        // Kiem tra dung sai
        Sleep(100);
        if(Q.getResult() == DapAn)
        {
            cout << "Bạn chọn đúng!!!" << endl;
            Sleep(300);
        }
        else
        {
            cout << "Bạn chọn sai." << endl;
            Sleep(200);
            cout << "Đáp án đúng là: " << Q.getResult() << endl;
            Sleep(400);
            SaveScore(dataP, size);
            break;
        }

        // Cau Tiep theo
        int c = data.Search(Q); // Tìm vị trí trong dũ liệu chính
        data[c].setCheck(false);  // Loại bỏ câu đã chơi trong dữ liệu chính
        size++;
        if(size == 15) // Toi da 15 cau
        {
            Sleep(200);
            cout << "\n\nChúc mừng bạn đã chiến thắng!" << endl;
            SaveScore(dataP, size);
        }
        dataNew.Clear(); // Xóa dữ liệu tạm
        data.ListNew(dataNew); // Thêm dữ liệu mới
        system("pause");
    }
}

void RandomAnswer(Question &Q, string A[4])
{
    srand(time(NULL));
    int chose = 1 + rand()%24;
    switch (chose)
    {
    case 1:
    {
        A[0] = Q.getA();  A[1] = Q.getB();  A[2] = Q.getC();  A[3] = Q.getD();
        break;
    }
    case 2:
    {
        A[0] = Q.getA();  A[1] = Q.getB();  A[2] = Q.getD();  A[3] = Q.getC();
        break;
    }        
    case 3:
    {
        A[0] = Q.getA();  A[1] = Q.getC();  A[2] = Q.getB();  A[3] = Q.getD();
        break;
    }
    case 4:
    {
        A[0] = Q.getA();  A[1] = Q.getC();  A[2] = Q.getD();  A[3] = Q.getB();
        break;
    }
    case 5:
    {
        A[0] = Q.getA();  A[1] = Q.getD();  A[2] = Q.getB();  A[3] = Q.getC();
        break;
    }
    case 6:
    {
        A[0] = Q.getA();  A[1] = Q.getD();  A[2] = Q.getC();  A[3] = Q.getB();
        break;
    }
    case 7:
    {
        A[0] = Q.getB();  A[1] = Q.getA();  A[2] = Q.getC();  A[3] = Q.getD();
        break;
    }
    case 8:
    {
        A[0] = Q.getB();  A[1] = Q.getA();  A[2] = Q.getD();  A[3] = Q.getC();
        break;
    }
    case 9:
    {
        A[0] = Q.getB();  A[1] = Q.getC();  A[2] = Q.getA();  A[3] = Q.getD();
        break;
    }
    case 10:
    {
        A[0] = Q.getB();  A[1] = Q.getC();  A[2] = Q.getD();  A[3] = Q.getA();
        break;
    } 
    case 11:
    {
        A[0] = Q.getB();  A[1] = Q.getD();  A[2] = Q.getA();  A[3] = Q.getC();
        break;
    }
    case 12:
    {
        A[0] = Q.getB();  A[1] = Q.getD();  A[2] = Q.getC();  A[3] = Q.getA();
        break;
    }
    case 13:
    {
        A[0] = Q.getC();  A[1] = Q.getA();  A[2] = Q.getB();  A[3] = Q.getD();
        break;
    }
    case 14:
    {
        A[0] = Q.getC();  A[1] = Q.getA();  A[2] = Q.getD();  A[3] = Q.getB();
        break;
    }
    case 15:
    {
        A[0] = Q.getC();  A[1] = Q.getB();  A[2] = Q.getA();  A[3] = Q.getD();
        break;
    }
    case 16:
    {
        A[0] = Q.getC();  A[1] = Q.getB();  A[2] = Q.getD();  A[3] = Q.getA();
        break;
    }
    case 17:
    {
        A[0] = Q.getC();  A[1] = Q.getD();  A[2] = Q.getA();  A[3] = Q.getB();
        break;
    }
    case 18:
    {
        A[0] = Q.getC();  A[1] = Q.getD();  A[2] = Q.getB();  A[3] = Q.getA();
        break;
    }
    case 19:
    {
        A[0] = Q.getD();  A[1] = Q.getA();  A[2] = Q.getB();  A[3] = Q.getC();
        break;
    }
    case 20:
    {
        A[0] = Q.getD();  A[1] = Q.getA();  A[2] = Q.getC();  A[3] = Q.getB();
        break;
    }case 21:
    {
        A[0] = Q.getD();  A[1] = Q.getB();  A[2] = Q.getA();  A[3] = Q.getC();
        break;
    }
    case 22:
    {
        A[0] = Q.getD();  A[1] = Q.getB();  A[2] = Q.getC();  A[3] = Q.getA();
        break;
    }
    case 23:
    {
        A[0] = Q.getD();  A[1] = Q.getC();  A[2] = Q.getA();  A[3] = Q.getB();
        break;
    }
    case 24:
    {
        A[0] = Q.getD();  A[1] = Q.getC();  A[2] = Q.getB();  A[3] = Q.getA();
        break;
    }
    default:
        break;
    }
}

int Select()
{
    int select = 0;
    cout << "\t\tLựa Chọn : ";
    cin >> select;
    return select;
}

void SelectMenu(ManagerQuestion &dataQuestion, ManagerPlayer &dataPlayer, ofstream &out)
{
    bool check = true;
    while(check)
    {
        system("cls");
        MenuGame();
        int select = Select();
        switch (select)
        {
        case 1:
        {
            ResetGame(dataQuestion);
            RandomQuestion(dataQuestion, dataPlayer);
            break;
        }
        case 2:
        {     
            cout << setw(5) << left << "STT" << setw(15) << left << "Ten" << setw(10) << left << "Diem so" << endl;
            dataPlayer.Sort();
            dataPlayer.Show();
            system("pause");
            break;
        }
        default:
            DataOut(dataPlayer, out);
            exit(1);
            break;
        }
    }
}


void SaveScore(ManagerPlayer &dataP, int score)
{
    Sleep(500);
    cout << "Bạn có muốn lưu điểm số không?" << endl;
    cout << "1. Có" << endl;
    cout << "2. Không" << endl;
    int select = Select();
    switch (select)
    {
    case 1:
    {
        Player P;
        string name;
        cout << "Nhập tên người chơi: ";
        fflush(stdin);
        getline(cin, name);
        P.setName(name);
        P.setScore(score);
        string T = TienThuong(score);
        P.setPrize(T);
        dataP.AddTail(P);
        cout << "Lưu thành công." << endl;
        Sleep(1000);
        break;
    }
    case 2:
    {
        break;
    }
    }
}

string TienThuong(int vt)
{
    if(vt == 0) return "0 vnd";
    if(vt == 1) return "100.000 vnd";
    if(vt == 2) return "250.000 vnd";
    if(vt == 3) return "400.000 vnd";
    if(vt == 4) return "600.000 vnd";
    if(vt == 5) return "1.000.000 vnd";
    if(vt == 6) return "2.500.000 vnd";
    if(vt == 7) return "6.000.000 vnd";
    if(vt == 8) return "10.000.000 vnd";
    if(vt == 9) return "15.000.000 vnd";
    if(vt == 10) return "25.000.000 vnd";
    if(vt == 11) return "40.000.000 vnd";
    if(vt == 12) return "60.000.000 vnd";
    if(vt == 13) return "85.000.000 vnd";
    if(vt == 14) return "110.000.000 vnd";
    if(vt == 15) return "150.000.000 vnd";
}

void MenuPlay(int vt)
{
    //SetColor(0,5);
    cout << "\n\n\t       -------------AI LÀ TRIỆU PHÚ--------------\n\n";

    cout << "\t\tSố tiền hiện có: " << TienThuong(vt) << endl << endl;

    if(CheckHeplCall)
        cout << "1. Gọi điện thoại  ";
    else
        cout << setw(19) << left << " ";
    if(CheckTuVanTaiCho)
        cout << "2. Tư vấn tại chỗ  ";
    else  
        cout << setw(19) << left << " ";
    if(CheckThamKhaoYKienKhanGia)
        cout << "3. Ý kiến khán giả  ";
    else
        cout << setw(20) << " ";
    if(CheckLoaiBo50)
        cout << "4. Loại bỏ 50% đáp án\n\n";
    else
        cout << "\n\n";
    //cout << "1. Gọi điện thoại  2. Tư vấn tại chỗ.  3. Ý kiến khán giả  4. Loại Bỏ 50% Đáp Án\n\n";
    cout <<"---------------------------------------------------------------------------------" << endl;
}

string doi(int val)
{
    if(val == 1) return "A";
    if(val == 2) return "B";
    if(val == 3) return "C";
    if(val == 4) return "D"; 
}
string SearchAnswer(Question &Q, string A[])
{
    if(Q.getResult() == A[0]) return "A";
    if(Q.getResult() == A[1]) return "B";
    if(Q.getResult() == A[2]) return "C";
    if(Q.getResult() == A[3]) return "D";
}

void HelpCall(Question &Q, int vt, string A[])
{
    Sleep(200);
    if(CheckLoaiBo50 ==  false && vt == ViTriCauChon)
    {
        cout << "Người giúp: Tôi chắc chắn rằng đó là đáp án " << SearchAnswer(Q, A) << endl;
        return;
    }
    int rate = 100 - (100/15 * vt) + rand()%(100/15 * vt);// càng cao tỷ lệ random càng lớn
    if(rate > 75)
    {
        cout << "Người giúp: Tôi chắc chắn rằng đó là đáp án " << SearchAnswer(Q, A) << endl;
    }
    else if(rate >= 50 && rate <=75)
    {
        srand(time(NULL));
        rate = 1 + rand()%4;
        cout << "Người giúp: Có thể là đáp án " << doi(rate) << endl;
    }
    else 
        cout << "Người giúp: Câu này khó đối với tôi" << endl;
}

void TuVanTaiCho(Question &Q, int vt, string A[])
{
    Sleep(200);
    for(int i = 1; i <= 3; i++)
    {
        Sleep(300);
        int rate = 100 - (100/15 * vt) + rand()%(vt * 100/15);
        if(CheckLoaiBo50 == false && vt == ViTriCauChon)
        {
            if(rate > 60)
                cout << "Người giúp " << i << ": " << SearchAnswer(Q, A) << endl;
            else
                cout << "Người giúp " << i << ": " << CauChon << endl;
        }
        else if(rate > 75)
        {
            cout << "Người giúp " << i << ": " << SearchAnswer(Q, A) << endl;
        }
        else 
        {
            rate = 1 + rand()%4;
            cout << "Người giúp " << i << ": " << doi(rate) << endl;
        }
    }
}

void ThamKhaoYKienKhanGia(Question &Q, int vt, string A[])
{
    Sleep(500);
    srand(time(NULL));
    int rate, t = 0;

    if(CheckLoaiBo50 == false && vt == ViTriCauChon)
    {
        rate = 70 - (70/15 * vt) + rand()%(vt * 70/15);

        cout << "A: ";
        if(SearchAnswer(Q, A) == "A")
            cout << rate << "%" << endl;
        else if(CauChon == "A")
            cout << 100 - rate << "%" << endl;
        else
            cout << "0%" << endl;


        cout << "B: ";
        if(SearchAnswer(Q, A) == "B")
            cout << rate << "%" << endl;
        else if(CauChon == "B")
            cout << 100 - rate << "%" << endl;
        else
            cout << "0%" << endl;
        

        cout << "C: ";
        if(SearchAnswer(Q, A) == "C")
            cout << rate << "%" << endl;
        else if(CauChon == "C")
            cout << 100 - rate << "%" << endl;
        else
            cout  << "0%" << endl;


        cout << "D: ";
        if(SearchAnswer(Q, A) == "D")
            cout << rate << "%" << endl;
        else if(CauChon == "D")
            cout << 100 - rate << "%" << endl;
        else
            cout << "0%" << endl;
        return;
    }


    cout << "A: ";
    if(SearchAnswer(Q, A) == "A")
    {
        rate = 45 - (45/15 * vt) + rand()%(vt * 45/15);
    }
    else
    {
        rate = 27 - (30/15 * vt) + rand()%(vt * 30/15);
    }
    t += rate;
    cout << rate << "%" << endl;

    cout << "B: ";
    if(SearchAnswer(Q, A) == "B")
    {
        rate = 45 - (45/15 * vt) + rand()%(vt * 45/15);
    }
    else
    {
        rate = 27 - (20/15 * vt) + rand()%(vt * 20/15);
    }
    t += rate;
    cout << rate << "%" << endl;

    cout << "C: ";
    if(SearchAnswer(Q, A) == "C")
    {
        rate = 45 - (45/15 * vt) + rand()%(vt * 45/15);
    } 
    else 
    {
        rate = 27 - (20/15 * vt) + rand()%(vt * 20/15);
    }
    t += rate;
    cout << rate << "%" << endl;

    cout << "D: " << 100 - t << "%" << endl;
   
}

void LoaiBo50(Question &Q, int vt, string A[])
{
    srand(time(NULL));
    int chon = 1 + rand()%4;
    while(doi(chon) == SearchAnswer(Q, A))
    {
        chon = 1 + rand()%4;
    }
    string DapAnChon = doi(chon);
    CauChon = DapAnChon;
    ViTriCauChon = vt;

    if((SearchAnswer(Q, A) == "A" && DapAnChon == "B") || (SearchAnswer(Q, A) == "B" && DapAnChon == "A"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << "A." << setw(40) << left << A[0] << "B." << setw(40) << left << A[1] << endl << endl
         << "---------------------------------------------------------------" << endl;
    }

    else if((SearchAnswer(Q, A) == "A" && DapAnChon == "C") || (SearchAnswer(Q, A) == "C" && DapAnChon == "A"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << "A." << A[0] << endl
        << "C." << A[2] << endl
         << "---------------------------------------------------------------" << endl;
    }

    else if((SearchAnswer(Q, A) == "A" && DapAnChon == "D") || (SearchAnswer(Q, A) == "D" && DapAnChon == "A"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << "A." << A[0] << endl
        << setw(37) << left << " " << "D." << A[3] << endl
         << "---------------------------------------------------------------" << endl;
    }

    else if((SearchAnswer(Q, A) == "B" && DapAnChon == "C") || (SearchAnswer(Q, A) == "C" && DapAnChon == "B"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << setw(37) << left << " " << "B." << A[1] << endl
        << "C." << A[2] << endl
        << "---------------------------------------------------------------" << endl;
    }

    else if((SearchAnswer(Q, A) == "B" && DapAnChon == "D") || (SearchAnswer(Q, A) == "D" && DapAnChon == "B"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << setw(37) << left << " " << "B." << A[1] << endl
        << setw(37) << left << " " << "D." << A[3] << endl
         << "---------------------------------------------------------------" << endl;
    }

    else if((SearchAnswer(Q, A) == "C" && DapAnChon == "D") || (SearchAnswer(Q, A) == "D" && DapAnChon == "C"))
    {
        MenuPlay(vt - 1);
        cout << "\nCâu " << vt << ": ";
        cout << Q << endl
        << endl
        << "C." << setw(40) << left << A[2] << "D." << setw(40) << left << A[3] << endl
        << "---------------------------------------------------------------" << endl;
    }
}

void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
