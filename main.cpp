#include <iostream>
#include "lab1.cpp"
#include "lab2.cpp"
#include "lab3.cpp"
#include "lab4.cpp"

using namespace std;

void printMenu ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Go to lab 1" << endl;
    cout << "2) Go to lab 2" << endl;
    cout << "3) Go to lab 3" << endl;
    cout << "4) Go to lab 4" << endl;
    cout << "5) Finish" << endl << endl;
}

int main()
{
    int choose;

    while (true)
    {
        printMenu ();
        choose = getch () - 48;
        cout << endl;
        switch (choose)
        {
            case 1:
                menuLab1 ();
                main ();
                break;
            case 2:
                menuLab2 ();
                main ();
                break;
            case 3:
                menuLab3 ();
                main ();
                break;
            case 4:
                menuLab4 ();
                main ();
                break;
            case 5:
                exit (0);
            default:
                cout << "Wrong input!" << endl << endl;
                break;
        }
    }

    return 0;
}
