#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <fstream>
using namespace std;
void gotoxy(short x, short y);
void moveHurdles();
void moveHurdles2();
void birdPositionUP();
void birdPositionDOWN();
void checkCondition();
int gap = 5;
int gap2 = 8;
int score{0};
int birdx = 30;
int birdy = 15;
int hurdlex = 80;
int hurdlex2 = 38;
bool gameRunning = true;
int main()
{
    system("CLS");
    int option = 0;
    int num1{1};
    int num2{1};
    string a;
    fstream file;
    file.open("FlyingBird-1.txt", ios::in);
    while (num1++ != 34)
    {
        getline(file, a);
        cout << a << endl;
    }
    file.close();
    getch();
    while (option != 2)
    {
        score = 0;
        num2 = 1;
        birdx = 28;
        birdy = 15;
        hurdlex = 80;
        hurdlex2 = 38;
        gameRunning = true;
        system("CLS");
        file.open("FlyingBird-3.txt", ios::in);
        int num3{0};
        while (num3++ != 34)
        {
            getline(file, a);
            cout << a << endl;
        }
        file.close();
        cin >> option;
        system("CLS");
        if (option == 1)
        {
            file.open("FlyingBird-2.txt", ios::in);
            while (num2++ != 34)
            {
                getline(file, a);
                cout << a << endl;
            }
            file.close();
            while (gameRunning)
            {

                moveHurdles();
                moveHurdles2();
                if (GetAsyncKeyState(VK_UP))
                {
                    birdPositionUP();
                    moveHurdles();
                    moveHurdles2();
                    if (GetAsyncKeyState(VK_UP))
                    {
                        birdPositionUP();
                    }
                    moveHurdles();
                    moveHurdles2();
                    if (GetAsyncKeyState(VK_UP))
                    {
                        birdPositionUP();
                    }
                }
                else
                {
                    birdPositionDOWN();
                    moveHurdles();
                    moveHurdles2();
                }
            }
        }
    }
}
void gotoxy(short x, short y)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(hStdout, position);
}
void moveHurdles()
{
    checkCondition();
    for (int y = 4; y < 25; y = y + 1)
    {
        if (y == gap)
        {
            y = y + 5;
        }

        gotoxy(hurdlex, y);
        cout << "*@*" << endl;
    }
    Sleep(40);
    for (int y = 4; y < 25; y = y + 1)
    {
        gotoxy(hurdlex, y);
        cout << "   " << endl;
    }
    if (hurdlex == 3)
    {
        hurdlex = 100;
        srand(time(NULL));
        gap = rand() % 10;
        gap += 5;
    }
    else
    {
        hurdlex--;
    }
    if (hurdlex == 25)
    {
        score += 1;
    }
}
void moveHurdles2()
{
    checkCondition();
    for (int y = 4; y < 25; y = y + 1)
    {
        if (y == gap2)
        {
            y = y + 5;
        }

        gotoxy(hurdlex2, y);
        cout << "*@*" << endl;
    }
    Sleep(40);
    for (int y = 4; y < 25; y = y + 1)
    {
        gotoxy(hurdlex2, y);
        cout << "   " << endl;
    }
    if (hurdlex2 == 3)
    {
        hurdlex2 = 100;
        srand(time(NULL));
        gap2 = rand() % 10;
        gap2 += 5;
    }
    else
    {
        hurdlex2--;
    }
    if (hurdlex2 == 25)
    {
        score += 1;
    }
}
void birdPositionUP()
{
    if (birdy > 5)
    {
        gotoxy(birdx, birdy);
        cout << "  ";
        birdy--;
        gotoxy(birdx, birdy);
        cout << "o>";
        checkCondition();
    }
}
void birdPositionDOWN()
{
    checkCondition();
    gotoxy(birdx, birdy);
    cout << "  ";
    birdy++;
    gotoxy(birdx, birdy);
    cout << "o>";
    checkCondition();
}
void checkCondition()
{
    if (birdy == 27)
    {
        gameRunning = false;
    }
    if (birdx == hurdlex || birdx == hurdlex + 1 || birdx == hurdlex + 2)
    {
        if (birdy == gap || birdy == gap + 1 || birdy == gap + 2 || birdy == gap + 3 || birdy == gap + 4)
        {
            gameRunning = true;
        }
        else
        {
            gameRunning = false;
        }
    }
    else if (birdx == hurdlex2 || birdx == hurdlex2 + 1 || birdx == hurdlex2 + 2)
    {
        if (birdy == gap2 || birdy == gap2 + 1 || birdy == gap2 + 2 || birdy == gap2 + 3 || birdy == gap2 + 4)
        {
            gameRunning = true;
        }
        else
        {
            gameRunning = false;
        }
    }
    gotoxy(131, 9);
    cout << "  ";
    gotoxy(131, 9);
    cout << score;
    gotoxy(134, 23);
    cout << "  ";
    gotoxy(134, 23);
    cout << 28 - birdy;
}