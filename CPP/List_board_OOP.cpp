#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

/*Set up OOP */

class Dev_kit
{
private:
    int id;
    string mfr;//Manufacturer
    string core;//Core MCU
    string series;//Series MCU
    string typemcu;//Type bit MCU
    string platform;//Name MCU
public:
    void setmfr(const string _mfr);
    void setcore(const string _core);
    void setseries(const string _series);
    void setmcu(const string _mcu);
    void setplatform(const string _platform);  
    void setid(int _id);
    
    int getid();
    string getmfr();
    string getcore();
    string getmcu();
    string getplatform();
};

void Dev_kit::setmfr(const string _mfr)
{
    mfr = _mfr;    
}

void Dev_kit::setcore(const string _core)
{
    core = _core;
}

void Dev_kit::setseries(const string _series)
{
    series = _series;
}

void Dev_kit::setmcu(const string _mcu)
{
    typemcu = _mcu;
}

void Dev_kit::setplatform(const string _platform)
{
  platform = _platform;
}

void Dev_kit::setid(int _id)
{
  id = _id;
}

int Dev_kit::getid()
{
    return id;
}

string Dev_kit::getmfr()
{
    return mfr;
}

string Dev_kit::getcore()
{
    return core;
}

string Dev_kit::getmcu()
{
    return typemcu;
}

string Dev_kit::getplatform()
{
    return platform;
}

 void output(vector<Dev_kit> &list_board)
{
    for (int id = 0; id < list_board.size(); id++)
        {
            cout << list_board[id].getid() << "\t" << list_board[id].getmfr() << "\t" << list_board[id].getcore() << "\t" << list_board[id].getmcu() << endl ;
        }
}

void exportcsv(vector<Dev_kit> &list_board)
{
    ofstream fout("list_board.csv");
    for (int id = 0; id < list_board.size(); id++)
        {
            fout << list_board[id].getid() << "\t" << list_board[id].getmfr() << "\t" << list_board[id].getcore() << "\t" << list_board[id].getmcu() << endl ;
        }
    fout.close();
}

void input(vector<Dev_kit> &list_board,Dev_kit &kit)
{
    int addid = 0;
    char text[100];
    addid++;
    kit.setid(addid);
    cout << "Adding MFR:\t";
    cin >> text;
    kit.setmfr(text);
    cout << "Adding Core:\t";
    cin >> text;
    kit.setcore(text);
    cout << "Adding MCU:\t";
    cin >> text;
    kit.setmcu(text);
    list_board.push_back(kit);
}

void menu()
{
    
}

int main(void)
{
    Dev_kit kit;
    vector<Dev_kit> list_board;
    string text;
    static int addid = 0;
    int num;
    while(1)
    {
        cout << "Adding?:\t";
        cin >> num;
        if(num == 1)
            {
                input(list_board,kit);
            }
        else if (num == 2)
        {
            exportcsv(list_board);
        }
           
        else
        {
            output(list_board);
        }
    }
}