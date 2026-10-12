#include <iostream>
#include <Windows.h>
using namespace std;

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Coord
{
    int x;
    int y;
};

class RectangleBox
{
    int width;
    int height;
    char symbol;
    Coord coords;
public:
    RectangleBox()
    {
        width = 10;
        height = 5;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }
    RectangleBox(int size)
    {
        if (size < 0)
        {
            size = abs(size);
        }
        width = size;
        height = size;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }
    RectangleBox(int userWidth, int userHeight)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        width = userWidth;
        height = userHeight;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }

    void Print()
    {
        SetPos(coords.x, coords.y);
        for (int i = 0; i < height; i++)
        {
            SetPos(coords.x, coords.y--);
            for (int i = 0; i < width; i++)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

    void ChangeRectangle(int userWidth, int userHeight, char userSymbol, int userX, int userY)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        if (userX < 0)
        {
            userX = 0;
        }
        if (userY < 0)
        {
            userY = 0;
        }
        
        width = userWidth;
        height = userHeight;
        symbol = userSymbol;
        coords.x = userX;
        coords.y = userY;
    }
    void ChangeWH(int userWidth, int userHeight)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        width = userWidth;
        height = userHeight;
    }
    void ChangeCoords(int userX, int userY)
    {
        if (userX < 0)
        {
            userX = 0;
        }
        if (userY < 0)
        {
            userY = 0;
        }
        coords.x = userX;
        coords.y = userY;
    }
};

int main()
{
    RectangleBox R;
    R.Print();
    Sleep(3000);
    system("cls");

    RectangleBox R2(4);
    R2.Print();
    Sleep(3000);
    system("cls");

    RectangleBox R3(3, -5);
    R3.Print();
    Sleep(3000);
    system("cls");

    

    R.ChangeRectangle(-10, -15, '@', 90, 50);
    R.Print();
    Sleep(2000);
    system("cls");

    R.ChangeWH(6,8);
    R.Print();
    Sleep(2000);
    system("cls");

    R.ChangeCoords(10,20);
    R.Print();
    Sleep(2000);
    system("cls");



    R.ChangeCoords(-10,-20);
    R.Print();
    Sleep(2000);
    system("cls");
}