#define _CRT_SECURE_NO_WARNINGS
#include "TranDau.h"
//
int TranDau::getPropertiesHero(Hero x)
{
    if (x.getProperties() == "Wood")
        return 1;
    else if (x.getProperties() == "Earth")
        return 2;
    else if (x.getProperties() == "Water")
        return 3;
    else if (x.getProperties() == "Fire")
        return 4;
    else
        return 5;
}
//
void TranDau::DocFile_ListHero(Hero list[])
{
    fstream f;
    f.open("ListHero.txt", ios::in);
    int i = 0;
    char temp;
    string name, prop;
    double blood, dam, def, speed;
    Hero l{};
    if (f.is_open())
    {
        for (; i < 10; i++)
        {
            getline(f, name, ';');
            if (name[0] == '\n')
                name.erase(name.begin() + 0);
            l.setName(name);
            getline(f, prop, ';'); l.setProperties(prop);
            f >> blood >> temp; l.setBlood(blood);
            f >> dam >> temp; l.setDamage(dam);
            f >> def >> temp; l.setDefend(def);
            f >> speed; l.setSpeed(speed);
            list[i] = l;
        }
        f.close();
    }
    else
        cout << "- Can not open this file!\n";
}
//
void TranDau::ChonHero(NguoiChoi& x, Hero list[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "\t- Hero " << i << " -";
        cout << list[i] << endl;
    }
    for (int i = 1; i <= 3; i++)
    {
        int luaChon = 0;
        cout << "- Nhap so thu tu Hero muon chon: ";
        cin >> luaChon;
        x.setListHero(list[luaChon], i);
        cout << x.getHero(i) << endl;
    }
}
//
void TranDau::NPCHero(Hero NPC[], Hero list[])
{
    srand((unsigned int)time(NULL));
    int index[3];
    bool flag1 = true;
    int i = 0;
    while (flag1)
    {
        bool flag2 = true;
        int res = rand() % (9 - 0 + 1) + 0;
        index[i] = res;
        if (i > 0)
        {
            for (int j = i - 1; j >= 0; j--)
                if (index[i] == index[j])
                    flag2 = false;
        }
        if (flag2 == false)
            continue;
        else
        {
            i++;
            if (i == 3)
                flag1 = false;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        NPC[i] = list[index[i]];
    }
}
//
int TranDau::MoiTruong(NguoiChoi& x, Hero NPC[])
{
    int res = rand() % (5 - 1 + 1) + 1;
    for (int i = 1; i <= 3; i++)
    {
        if (this->getPropertiesHero(x.getHero(i)) == res)
            continue;
        if (this->getPropertiesHero(x.getHero(i)) == 1 && (res == 5 || res == 3))
        {
            if (this->getPropertiesHero(x.getHero(i)) == 1 && (res == 5))
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(x.getHero(i)) == 1 && res == 3)
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 1.05);
                x.getHero(i).setSpeed(x.getHero(i).getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(x.getHero(i)) == 2 && (res == 1 || res == 4))
        {
            if (this->getPropertiesHero(x.getHero(i)) == 2 && (res == 1))
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(x.getHero(i)) == 2 && res == 4)
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 1.05);
                x.getHero(i).setSpeed(x.getHero(i).getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(x.getHero(i)) == 3 && (res == 2 || res == 5))
        {
            if (this->getPropertiesHero(x.getHero(i)) == 3 && (res == 2))
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(x.getHero(i)) == 3 && res == 5)
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 1.05);
                x.getHero(i).setSpeed(x.getHero(i).getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(x.getHero(i)) == 4 && (res == 3 || res == 1))
        {
            if (this->getPropertiesHero(x.getHero(i)) == 4 && (res == 3))
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(x.getHero(i)) == 4 && res == 1)
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 1.05);
                x.getHero(i).setSpeed(x.getHero(i).getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(x.getHero(i)) == 5 && (res == 4 || res == 2))
        {
            if (this->getPropertiesHero(x.getHero(i)) == 5 && (res == 4))
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(x.getHero(i)) == 5 && res == 2)
            {
                x.getHero(i).setBlood(x.getHero(i).getBlood() * 1.05);
                x.getHero(i).setSpeed(x.getHero(i).getSpeed() * 0.9);
            }
        }
    }
    //
    for (int i = 0; i < 3; i++)
    {
        if (this->getPropertiesHero(NPC[i]) == res)
            continue;
        if (this->getPropertiesHero(NPC[i]) == 1 && (res == 5 || res == 3))
        {
            if (this->getPropertiesHero(NPC[i]) == 1 && (res == 5))
            {
                NPC[i].setBlood(NPC[i].getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(NPC[i]) == 1 && res == 3)
            {
                NPC[i].setBlood(NPC[i].getBlood() * 1.05);
                NPC[i].setSpeed(NPC[i].getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(NPC[i]) == 2 && (res == 1 || res == 4))
        {
            if (this->getPropertiesHero(NPC[i]) == 2 && (res == 1))
            {
                NPC[i].setBlood(NPC[i].getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(NPC[i]) == 2 && res == 4)
            {
                NPC[i].setBlood(NPC[i].getBlood() * 1.05);
                NPC[i].setSpeed(NPC[i].getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(NPC[i]) == 3 && (res == 2 || res == 5))
        {
            if (this->getPropertiesHero(NPC[i]) == 3 && (res == 2))
            {
                NPC[i].setBlood(NPC[i].getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(NPC[i]) == 3 && res == 5)
            {
                NPC[i].setBlood(NPC[i].getBlood() * 1.05);
                NPC[i].setSpeed(NPC[i].getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(NPC[i]) == 4 && (res == 3 || res == 1))
        {
            if (this->getPropertiesHero(NPC[i]) == 4 && (res == 3))
            {
                NPC[i].setBlood(NPC[i].getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(NPC[i]) == 4 && res == 1)
            {
                NPC[i].setBlood(NPC[i].getBlood() * 1.05);
                NPC[i].setSpeed(NPC[i].getSpeed() * 0.9);
            }
        }
        else if (this->getPropertiesHero(NPC[i]) == 5 && (res == 4 || res == 2))
        {
            if (this->getPropertiesHero(NPC[i]) == 5 && (res == 4))
            {
                NPC[i].setBlood(NPC[i].getBlood() * 0.97);
            }
            else if (this->getPropertiesHero(NPC[i]) == 5 && res == 2)
            {
                NPC[i].setBlood(NPC[i].getBlood() * 1.05);
                NPC[i].setSpeed(NPC[i].getSpeed() * 0.9);
            }
        }
    }
    return res;
}
//
void TranDau::HiepDau(Hero& x, Hero& pc)
{
    auto start = steady_clock::now();
    cout << "*** Bat dau hiep dau \n\t. . .\n";
    if (pc.getBlood() > 0.0 && x.getBlood() > 0.0)
    {
        if (pc.getSpeed() >= x.getSpeed())
        {
            while (x.getBlood() > 0 && pc.getBlood() > 0)
            {
                x.setBlood(x.getBlood() - pc.getDamage() + x.getDefend());
                if (x.getBlood() < 0)
                    break;
                auto start_t_Person = steady_clock::now();
                // Bắt đầu chờ thời gian hồi chiêu
                pc.setBlood(pc.getBlood() - x.getDamage() + pc.getDefend());
                if (pc.getBlood() < 0)
                    break;
                auto start_t_PC = steady_clock::now();
                auto end_t_Person = steady_clock::now();
                // Kết thúc một lượt đánh
                duration<double, std::milli> total_t = end_t_Person - start_t_Person;
                while (total_t.count() < x.getSpeed()) // Chờ đủ thời gian hồi chiêu để bắt đầu một lượt đánh tiếp theo
                {
                    auto end_t = steady_clock::now();
                    total_t = end_t - start_t_Person;
                }
            }
        }
        else
        {
            while (x.getBlood() > 0 && pc.getBlood() > 0)
            {
                pc.setBlood(pc.getBlood() - x.getDamage() + pc.getDefend());
                if (pc.getBlood() < 0)
                    break;
                auto start_t = steady_clock::now();
                // Bắt đầu chờ thời gian hồi chiêu
                x.setBlood(x.getBlood() - pc.getDamage() + x.getDefend());
                if (x.getBlood() < 0)
                    break;
                auto end_t = steady_clock::now();
                // Kết thúc một lượt đánh
                duration<double, std::milli> total_t = end_t - start_t;
                while (total_t.count() < pc.getSpeed()) // Chờ đủ thời gian hồi chiêu để bắt đầu một lượt đánh tiếp theo
                {
                    auto end_t2 = steady_clock::now();
                    total_t = end_t2 - start_t;
                }
            }
        }
    }
    auto end = steady_clock::now();
    duration<double, std::milli> total = end - start;
    cout << "\n- Thoi gian tran dau = " << total.count() << " milli second(s)" << endl;
}
//
int TranDau::is_Victory(Hero Person, Hero PC, int& winPerson, int& winNPC)
{
    if (Person.getBlood() > PC.getBlood())
        winPerson++;
    else if (Person.getBlood() < PC.getBlood())
        winNPC++;
    if (winPerson > winNPC)
        return 1;
    else if (winPerson < winNPC)
        return 2;
    else
        return 0;
}
//
void TranDau::Result(NguoiChoi& x, Hero NPC[], int RESULT)
{
    GoTo(47, 0);
    if (RESULT == 1)
        cout << "\t- TEAM " << x.getTenNguoiChoi() << " VICTORY -\n";
    else if (RESULT == 2)
        cout << "\t- TEAM NPC VICTORY -\n";
    else
        cout << "\t- MATCH DRAW -\n";
    //
    GoTo(25, 2);
    cout << "\t  Team " << x.getTenNguoiChoi() << "\t\t\t\t\t Team NPC";
    for (int i = 0; i < 3; i++)
    {
        GoTo(25, i + 3);
        cout << x.getHero(i + 1).getName() << " : " << x.getHero(i + 1).getProperties() << ";" << x.getHero(i + 1).getDamage() << ";"
            << x.getHero(i + 1).getDefend() << ";" << x.getHero(i + 1).getBlood() << ";" << x.getHero(i + 1).getSpeed();
    }
    for (int i = 0; i < 3; i++)
    {
        GoTo(65, i + 3);
        cout << "\t" << NPC[i].getName() << " : " << NPC[i].getProperties() << ";" << NPC[i].getDamage() << ";"
            << NPC[i].getDefend() << ";" << NPC[i].getBlood() << ";" << NPC[i].getSpeed() << endl;
    }
}
//
void TranDau::GhiFile_LOG(NguoiChoi& x, Hero NPC[], tm* tlm, int winPerson, int winNPC)
{
    fstream f;
    if (f.is_open())
        f.close();
    f.open("LOG.txt", ios::out | ios::app);
    if (f.is_open())
    {
        f << tlm->tm_hour << "/" << tlm->tm_min << "/" << tlm->tm_sec << "/" << tlm->tm_mday << "/" << 1 + tlm->tm_mon << "/" << 1900 + tlm->tm_year << "|";
        f << x.getTenNguoiChoi() << "|" << x.getHero(1).getName() << "/" << x.getHero(2).getName() << "/" << x.getHero(3).getName() << "|";
        f << "NPC|" << NPC[0].getName() << "/" << NPC[1].getName() << "/" << NPC[2].getName() << "|";
        f << winPerson << "/" << winNPC << endl;
        f.close();
    }
    else
        cout << "- Can not open this file!\n";
}
//
void TranDau::DocFile_LOG(string hiepDau[], size_t& i)
{
    fstream f;
    if (f.is_open())
        f.close();
    f.open("LOG.txt", ios::in);
    //
    i = 0;
    //
    cout << "Gio/Phut/Giay/Ngay/Thang/Nam\n\n";
    //
    while (!f.eof())
    {
        string line;
        getline(f, hiepDau[i]);
        if (hiepDau[i] == "")
            break;
        size_t j = 0; 
        while (hiepDau[i][j] != '|')
            line.push_back(hiepDau[i][j++]);
        cout << line << endl;
        i++;
    }
}
//
bool TranDau::HienThiHiepDau(string hiepDau, string LOG_thoiGian)
{   
    string line;
    size_t i = 0;
    while (hiepDau[i] != '|')
        line.push_back(hiepDau[i++]);
    if (LOG_thoiGian == line)
        return true;
    return false;
}
//
void GoTo(SHORT posX, SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
    //
    SetConsoleCursorPosition(hStdout, Position);
}
//
void Program(TranDau& tranDau, string TRANDAU[])
{
    Hero danhSach_HERO[10];
    tranDau.DocFile_ListHero(danhSach_HERO);
    //
    do
    {
        cout << "---------- Game Dau Tuong ----------\n";
        cout << "\n1. Tro choi moi";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n-- Nhap lua chon: ";
        int luaChon_1 = -1;
        while (!(cin >> luaChon_1) || luaChon_1 < 0 || luaChon_1>1)
        {
            cin.clear();
            cin.ignore(20, '\n');
            cout << "\n- Nhap sai lua chon, vui long nhap lai: ";
        }
        //
        int tiSo = -1;
        //
        switch (luaChon_1)
        {
        default:
            break;
        case 0:
        {
            system("cls");
            cout << "- Ban da chon thoat chuong trinh.\n";
            exit(0);
        }
        case 1:
        {
            system("cls");
            string tenNguoiChoi = "";
            cout << "- Nhap ten nguoi choi: ";
            cin.ignore();
            getline(cin, tenNguoiChoi);
            //
            NguoiChoi nguoiChoi{ tenNguoiChoi };
            //
            int luaChon_2 = -1;
            do
            {
                system("cls");
                cout << "1. Dau voi NPC\n";
                cout << "2. Xem LOG\n";
                cout << "0. Quay lai\n";
                cout << "-- Nhap lua chon: ";
                while (!(cin >> luaChon_2) || luaChon_2 < 0 || luaChon_2 > 2)
                {
                    cin.clear();
                    cin.ignore(20, '\n');
                    cout << "\n- Nhap sai lua chon, vui long nhap lai: ";
                }
                //
                switch (luaChon_2)
                {
                default:
                    break;
                case 1:
                {
                    system("cls");
                    //
                    cout << "\n- Nguoi choi chon Hero -\n";
                    //
                    tranDau.ChonHero(nguoiChoi, danhSach_HERO);
                    CungDoi(nguoiChoi.getHero(1), nguoiChoi.getHero(2), nguoiChoi.getHero(3));
                    //
                    system("cls");
                    nguoiChoi.HienThiTeamHero();
                    //
                    Hero NPC[3];
                    cout << "\n----- NPC TEAM -----\n";
                    tranDau.NPCHero(NPC, danhSach_HERO);
                    CungDoi(NPC[0], NPC[1], NPC[2]);
                    for (int i = 0; i < 3; i++)
                    {
                        cout << "\t- " << i + 1 << " -";
                        cout << NPC[i] << endl;
                    }
                    //
                    system("pause");
                    system("cls");
                    //
                    int E = tranDau.MoiTruong(nguoiChoi, NPC);
                    if (E == 1)
                        cout << "- Moi truong cua tran dau: WOOD -\n";
                    else if (E == 2)
                        cout << "- Moi truong: EARTH -\n";
                    else if (E == 3)
                        cout << "- Moi truong: WATER -\n";
                    else if (E == 4)
                        cout << "- Moi truong: FIRE -\n";
                    else if (E == 5)
                        cout << "- Moi truong: METAL -\n";
                    //
                    Sleep(2000);
                    system("cls");
                    //
                    int tiSoNguoiChoi = 0, tiSoNPC = 0;
                    //
                    for (int i = 0; i < 3; i++)
                    {
                        if (nguoiChoi.DoiKhang(NPC[i], i + 1))
                        {

                            cout << " \t- Hiep dau " << i + 1 <<" -\n";
                            cout << nguoiChoi.getHero(i + 1) << "\n\t - VS -\n" << NPC[i] << endl;
                        }
                        //
                        tranDau.HiepDau(nguoiChoi.getHero(i + 1), NPC[i]);
                        //
                        cout << "\n*** Ket thuc hiep dau " << i + 1 << " -\n";
                        //
                        if (NPC[i].getBlood() < nguoiChoi.getHero(i + 1).getBlood())
                        {
                            cout << "\t- " << NPC[i].getName() << ": THUA!\n";
                            NPC[i].setBlood(0.0);
                        }
                        else if (NPC[i].getBlood() == nguoiChoi.getHero(i + 1).getBlood())
                            cout << "\t\n- HOA -\n";
                        else
                        {
                            cout << "\t- " << nguoiChoi.getHero(i + 1).getName() << ": THUA!\n";
                            nguoiChoi.getHero(i + 1).setBlood(0.0);
                        }
                        //
                        cout << nguoiChoi.getHero(i + 1) << NPC[i];
                        tiSo = tranDau.is_Victory(nguoiChoi.getHero(i + 1), NPC[i], tiSoNguoiChoi, tiSoNPC);
                        system("pause");
                        system("cls");
                    }
                    //
                    tranDau.Result(nguoiChoi, NPC, tiSo);
                    //
                    time_t now = time(0);
                    cout << "\n- Current Time is: " << endl;
                    //
                    tm* ltm = localtime(&now);
                    //
                    cout << "\tYear: " << 1900 + ltm->tm_year << endl;
                    cout << "\tMonth: " << 1 + ltm->tm_mon << endl;
                    cout << "\tDay: " << ltm->tm_mday << endl;
                    cout << "\tTime: " << 1 + ltm->tm_hour << ":" << 1 + ltm->tm_min << ":" << 1 + ltm->tm_sec << endl;
                    tranDau.GhiFile_LOG(nguoiChoi, NPC, ltm, tiSoNguoiChoi, tiSoNPC);
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:
                {
                    int luaChon_3 = -1;
                    do
                    {
                        size_t soLuongHiepDau = 0;
                        system("cls");
                        cout << "\t\t\t\t\t-- XEM LOG ---\n*********************************************************************************************************\n";
                        tranDau.DocFile_LOG(TRANDAU, soLuongHiepDau);
                        //
                        cout << "------------------------------------------------\n";
                        cout << "1. Nhap thoi gian de xem thong tin\n";
                        cout << "0. Quay lai\n";
                        cout << "-- Nhap lua chon: ";
                        while (!(cin >> luaChon_3) || luaChon_3 < 0 || luaChon_3 > 1)
                        {
                            cin.clear();
                            cin.ignore(20, '\n');
                            cout << "\n- Nhap sai lua chon, vui long nhap lai: ";
                        }
                        //
                        switch (luaChon_3)
                        {
                        default:
                            break;
                        case 1:
                        {
                            int Gio = 0, Phut = 0, Giay = 0, Ngay = 0, Thang = 0, Nam = 0;
                            cout << "- Nhap Gio: "; cin >> Gio;
                            cout << "- Nhap Phut: "; cin >> Phut;
                            cout << "- Nhap Giay: "; cin >> Giay;
                            cout << "- Nhap Ngay: "; cin >> Ngay;
                            cout << "- Nhap Thang: "; cin >> Thang;
                            cout << "- Nhap Nam: "; cin >> Nam;
                            string thoiGian = to_string(Gio) + "/" + to_string(Phut) + "/" + to_string(Giay) + "/" + to_string(Ngay) + "/" + to_string(Thang) + "/" + to_string(Nam);
                            for (size_t i = 0; i < soLuongHiepDau; i++)
                            {
                                if (tranDau.HienThiHiepDau(TRANDAU[i], thoiGian))
                                {
                                    cout << "\t\n-- Chi tiet hiep dau --\n\n";
                                    cout << "- Gio/Phut/Giay/Ngay/Thang/Nam|<TenNguoiChoi>|<DanhSachHero>|NPC|<DanhSachHero>|TiSo\n- ";
                                    cout << TRANDAU[i] << endl << endl;
                                }
                            }
                            system("pause");
                            system("cls");
                            break;
                        }
                        }
                    } while (luaChon_3 != 0);
                    system("pause");
                    system("cls");
                    break;
                }
                }
            } while (luaChon_2 != 0);
            system("pause");
            system("cls");
            break;
        }
        }
    } while (1);
}