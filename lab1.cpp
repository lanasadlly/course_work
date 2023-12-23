#include <iostream>
#include <conio.h>
using namespace std;

void printMenuLab1 ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Print the number of Bytes needed for different types" << endl;
    cout << "2) Print a binary representation of an int value" << endl;
    cout << "3) Print a binary representation of a float value" << endl;
    cout << "4) Print a binary representation of a double value" << endl;
    cout << "5) Go to another lab" << endl;
}

void doPoint1Lab1 ()
{
    cout << "int: " << sizeof (int) << " Bytes" << endl;
    cout << "short int: " << sizeof (short int) << " Bytes" << endl;
    cout << "long int: " << sizeof (long int) << " Bytes" << endl;
    cout << "float: " << sizeof (float) << " Bytes" << endl;
    cout << "double: " << sizeof (double) << " Bytes" << endl;
    cout << "long double: " << sizeof (long double) << " Bytes" << endl;
    cout << "char: " << sizeof (char) << " Byte" << endl;
    cout << "bool: " << sizeof (bool) << " Byte" << endl << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint2Lab1 ()
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 0 || choose == 1))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        cout << "Write '1' to see result with idz or '0' for without" << endl << endl;
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    int value;
    short unsigned order = 32;
    unsigned mask = 1 << (order - 1);
    cout << "Enter an int value: ";
    cin >> value;
    cout << endl;

    if (value < 0 && choose)
    {
        cout << "You have entered a negative value, so even bits will be replaced with '0'" << endl;
        cout << "Changed binary representation of int " << value << " is:" << endl;
    }
    else if (value > 0 && choose)
    {
        cout << "You have entered a positive value, so odd bits will be replaced with '1'" << endl;
        cout << "Changed binary representation of int " << value << " is:" << endl;
    }
    else
        cout << "Binary representation of int " << value << " is:" << endl;

    for (short i = 1; i <= order ; i++)
    {
        if (value < 0 && i % 2 == 0 && choose)
            putchar ('0');
        else if (value > 0 && i % 2 == 1 && choose)
            putchar ('1');
        else
            putchar (value & mask ? '1' : '0');
        if (i % 8 == 0 || i % order == 1)
            cout << ' ';
        mask >>= 1;
    }

    cout << endl;
    cout << "- ----------------------------------" << endl;
    cout << "sign       significant digits" << endl;
    cout << endl << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();

}

void doPoint3Lab1 ()
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 0 || choose == 1))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        cout << "Write '1' to see result with idz or '0' for without" << endl << endl;
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    union
    {
        int tool;
        float value;
    };
    short unsigned order = 32;
    unsigned mask = 1 << (order - 1);
    cout << "Enter a float value: ";
    cin >> value;
    cout << endl;

     if (value < 0 && choose)
    {
        cout << "You have entered a negative value, so even bits will be replaced with '0'" << endl;
        cout << "Changed binary representation of float " << value << " is:" << endl;
    }
    else if (value > 0 && choose)
    {
        cout << "You have entered a positive value, so odd bits will be replaced with '1'" << endl;
        cout << "Changed binary representation of float " << value << " is:" << endl;
    }
    else
        cout << "Binary representation of float " << value << " is:" << endl;

    for (short i = 1; i <= order ; i++)
    {
        if (value < 0 && i % 2 == 0 && choose)
            putchar ('0');
        else if (value > 0 && i % 2 == 1 && choose)
            putchar ('1');
        else
            putchar (tool & mask ? '1' : '0');
        if (i % order == 1 || i % order == 9)
            cout << ' ';
        mask >>= 1;
    }

    cout << endl;
    cout << "- -------- ------------------------" << endl;
    cout << "sign exponent     mantissa" << endl;
    cout << " of" << endl;
    cout << "mantissa";
    cout << endl << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint4Lab1 ()
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 0 || choose == 1))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        cout << "Write '1' to see result with idz or '0' for without" << endl << endl;
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    union
    {
        int tool [2];
        double value;
    };
    short unsigned order = 64;
    unsigned mask = 1 << (order / 2 - 1);
    cout << "Enter a double value: ";
    cin >> value;
    cout << endl;

     if (value < 0 && choose)
    {
        cout << "You have entered a negative value, so even bits will be replaced with '0'" << endl;
        cout << "Changed binary representation of double " << value << " is:" << endl;
    }
    else if (value > 0 && choose)
    {
        cout << "You have entered a positive value, so odd bits will be replaced with '1'" << endl;
        cout << "Changed binary representation of double " << value << " is:" << endl;
    }
    else
        cout << "Binary representation of double " << value << " is:" << endl;

    for (short i = 1; i <= order / 2 ; i++)
    {
        if (value < 0 && i % 2 == 0 && choose)
            putchar ('0');
        else if (value > 0 && i % 2 == 1 && choose)
            putchar ('1');
        else
            putchar (tool [0] & mask ? '1' : '0');
        if (i % order == 1 || i % order == 12)
            cout << ' ';
        mask >>= 1;
    }

    mask = 1 << (order / 2 - 1);

    for (short i = order / 2 + 1; i <= order; i++)
    {
        if (value < 0 && i % 2 == 0 && choose)
            putchar ('0');
        else if (value > 0 && i % 2 == 1 && choose)
            putchar ('1');
        else
            putchar (tool [1] & mask ? '1' : '0');
        mask >>= 1;
    }

    cout << endl;
    cout << "- ----------- -----------------------------------------------------" << endl;
    cout << "sign exponent                      mantissa" << endl;
    cout << " of" << endl;
    cout << "mantissa";
    cout << endl << endl;
}

void menuLab1()
{
    int choose;
    while (true)
    {
        printMenuLab1 ();
        choose = getch () - 48;
        cout << endl;
        if (choose == 5)
            break;
        switch (choose)
        {
            case 1:
                doPoint1Lab1 ();
                break;
            case 2:
                doPoint2Lab1 ();
                break;
            case 3:
                doPoint3Lab1 ();
                break;
            case 4:
                doPoint4Lab1 ();
                break;
            default:
                cout << "Wrong input!" << endl << endl;
                break;
        }
    }
}
