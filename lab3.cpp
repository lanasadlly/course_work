#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <Windows.h>
#include <conio.h>

using namespace std;

void printMenuLab3 ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Fill a square matrix N*N with random int values from 1 to N*N" << endl;
    cout << "2) Make a new matrix out of a matrix filled in point 1" << endl;
    cout << "3) Sort matrix elements" << endl;
    cout << "4) Decrease, increase, multiply or divide all matrix elements by some value" << endl;
    cout << "5) Fill another matrix N*N with random values from 1 to N*N" << endl;
    cout << "   Subtract the first matrix from the second. Show step by step" << endl;
    cout << "6) Go to another lab" << endl;
}

void printPoint1Lab3 (int b)
{
    if (b == 1)
    {
        cout << "Choose a matrix order:" << endl;
        cout << "1) N = 6" << endl;
        cout << "2) N = 8" << endl;
        cout << "3) N = 10" << endl;
    }
    if (b == 2)
    {
        cout << "Choose a filling scheme:" << endl;
        cout << " 1)  ---------------     2)  --------------- " << endl;
        cout << "    |               |       |               |" << endl;
        cout << "    |  1 2..>.....  |       | 1  .>..  .>.. |" << endl;
        cout << "    |            .  |       | 2  .  .  .  . |" << endl;
        cout << "    |  .....>..  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .      .  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .    <..  .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .         .  |       | .  .  .  .  . |" << endl;
        cout << "    |  .....<.....  |       | .>..  .>..  . |" << endl;
        cout << "    |               |       |               |" << endl;
        cout << "     ---------------         --------------- " << endl;
    }
}

void printPoint2Lab3 ()
{
    cout << "Choose a changing scheme:" << endl;
    cout << " 1)  ---------------     2)  --------------- " << endl;
    cout << "    |       |       |       |  _    |    _  |" << endl;
    cout << "    |  /\\...|....>  |       | |\\    |    /| |" << endl;
    cout << "    |   .   |   .   |       |    \\  |  /    |" << endl;
    cout << "    |   .   |   .   |       |      \\|/      |" << endl;
    cout << "    |---.-----------|       |---------------|" << endl;
    cout << "    |   .   |   .   |       |      /|\\      |" << endl;
    cout << "    |   .   |   .   |       |    /  |  \\    |" << endl;
    cout << "    |  <....|...\\/  |       | |/    |    \\| |" << endl;
    cout << "    |       |       |       |  -    |    -  |" << endl;
    cout << "     ---------------         --------------- " << endl << endl;
    cout << " 3)  ---------------     4)  --------------- " << endl;
    cout << "    |       |       |       |       |       |" << endl;
    cout << "    |  /\\   |   /\\  |       |  <....|....>  |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |---------------|       |---------------|" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |   .   |   .   |       |       |       |" << endl;
    cout << "    |  \\/   |   \\/  |       |  <....|....>  |" << endl;
    cout << "    |       |       |       |       |       |" << endl;
    cout << "     ---------------         --------------- " << endl;
}

void printPoint3Lab3 ()
{
    cout << "Choose a sorting method:" << endl;
    cout << "1) Bubble sort" << endl;
    cout << "2) Shaker sort" << endl;
    cout << "3) Comb sort" << endl;
    cout << "4) Insert sort" << endl;
    cout << "5) Quick sort" << endl;
}

void printPoint4Lab3 ()
{
    cout << "Choose an action:" << endl;
    cout << "1) Decrease" << endl;
    cout << "2) Increase" << endl;
    cout << "3) Multiply" << endl;
    cout << "4) Divide" << endl;
}

void showMatrixLab3 (int *arr, int order)
{
    int *end = arr + order * order - 1;
    for (int *curr = arr; curr <= end; curr++)
    {
        cout << setw (3) << *curr << "  ";
        if ((curr - arr) % order == order - 1)
            cout << endl << endl << endl;
    }
}

void doFill1Lab3 (int *arr, int order)
{
    int *start = arr;
    int *end = arr + order * order - 1;
    int len = order - 1;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);

    while (start <= end)
    {
        for (int *curr = start; curr <= start + len; curr++)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        for (int *curr = start + len + order; curr <= end; curr += order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        for (int *curr = end - 1; curr >= end - len; curr--)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        for (int *curr = end - len - order; curr > start; curr -= order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }
        len -= 2;
        start = start + order + 1;
        end = end - order - 1;
    }

    destCoord.X = 0;
    destCoord.Y = order * 3 - 1;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << endl;
    cout.flush();
}

void doFill2Lab3 (int *arr, int order)
{
    int *start = arr;
    int *end = arr + order * (order - 1);

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);

    while (end <= arr + order * order - 1)
    {
        for (int *curr = start; curr <= end; curr += order)
        {
            *curr = rand () % order * order + 1;
            destCoord.X = (((curr - arr) % order) * 5);
            destCoord.Y = (((curr - arr) / order) * 3);
            SetConsoleCursorPosition (hStdout, destCoord);
            cout << setw (3) << *curr;
            cout.flush();
            Sleep (300);
        }

        if (end + 1 <= arr + order * order - 1)
        {
            for (int *curr = end + 1; curr >= start + 1; curr -= order)
            {
                *curr = rand () % order * order + 1;
                destCoord.X = (((curr - arr) % order) * 5);
                destCoord.Y = (((curr - arr) / order) * 3);
                SetConsoleCursorPosition (hStdout, destCoord);
                cout << setw (3) << *curr;
                cout.flush();
                Sleep (300);
            }
        }
        start += 2;
        end += 2;
    }
    destCoord.X = 0;
    destCoord.Y = order * 3 - 1;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << endl;
    cout.flush();
}

void doScheme1Lab3 (int *arr, int order)
{
    int half = order / 2;

    for (int *beginStr = arr; beginStr < arr + order * half; beginStr += order)
        for (int *currLeft = beginStr; currLeft < beginStr + half; currLeft++)
            swap (*currLeft, *(currLeft + half));

    for (int *beginCln = arr; beginCln < arr + half; beginCln++)
        for (int *currUpper = beginCln; currUpper < beginCln + order * half; currUpper += order)
            swap (*currUpper, *(currUpper + order * half));

    for (int *beginStr = arr + order * half; beginStr < arr + order * order; beginStr += order)
        for (int *currLeft = beginStr; currLeft < beginStr + half; currLeft++)
            swap (*currLeft, *(currLeft + half));
}

void doScheme2Lab3 (int *arr, int order)
{
    int half = order / 2;

    for (int *beginStr = arr; beginStr < arr + order * order; beginStr += order)
        for (int *currLeft = beginStr; currLeft < beginStr + half; currLeft++)
            swap (*currLeft, *(currLeft + half));

    for (int *beginCln = arr; beginCln < arr + order; beginCln++)
        for (int *currUpper = beginCln; currUpper < beginCln + order * half; currUpper += order)
            swap (*currUpper, *(currUpper + order * half));
}

void doScheme3Lab3 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginCln = arr; beginCln < arr + order; beginCln++)
        for (int *currUpper = beginCln; currUpper < beginCln + order * half; currUpper += order)
            swap (*currUpper, *(currUpper + order * half));
}

void doScheme4Lab3 (int *arr, int order)
{
    int half = order / 2;
    for (int *beginStr = arr; beginStr < arr + order * order; beginStr += order)
        for (int *currLeft = beginStr; currLeft < beginStr + half; currLeft++)
            swap (*currLeft, *(currLeft + half));
}

void doBubbleSortLab3 (int *arr, int order)
{
    int *end = arr + order * order - 1;
    bool swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int *curr = arr; curr < end; curr ++)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        end--;
    }
}

void doShakerSortLab3 (int *arr, int order)
{
    bool swapped = 1;
    int *start = arr;
    int *end = arr + order * order - 1;
    while (swapped)
    {
        swapped = 0;
        for (int *curr = start; curr < end; curr++)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        end--;
        for (int *curr = end - 1; curr >= start; curr--)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        start++;
    }
}

void doCombSortLab3 (int *arr, int order)
{
    int *start = arr;
    int *end = arr + order * order - 1;
    bool swapped = 1;
    float k = 1.247, step = order * order - 1;
    while (step >= 1)
    {
        for (int *curr = start; curr + int (step) < end + 1; curr++)
        {
            if (*curr > *(curr + int (step)))
                swap (*curr, *(curr + int (step)));
        }
        step /= k;
    }

    while (swapped)
    {
        swapped = 0;
        for (int *curr = arr; curr < end; curr ++)
        {
            if (*curr > *(curr + 1))
            {
                swap (*curr, *(curr + 1));
                swapped = 1;
            }
        }
        end--;
    }
}

void doInsertSortLab3 (int *arr, int order)
{
    int key;
    int *j;
    for(int *curr = arr + 1; curr < arr + order * order; curr++)
    {
        j = curr - 1;
        key = *curr;
        while (j >= arr && *j > key)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}

void doQuickSortLab3 (int *arr, int *start, int *end)
{
    int *left = start;
    int *right = end;
    int key = *start;
    int countLess = 0;
    for (int *curr = start; curr <= end; curr++)
        if (*curr < key)
            countLess += 1;
    swap (*start, *(start + countLess));

    while (left <= right)
    {
        while (*left < key)
            left++;
        while (*right >= key)
            right--;
        if (left < right)
        {
            swap (*left, *right);
            left++;
            right--;
        }
    }

    if (right > start)
        doQuickSortLab3 (arr, start, right);
    if (left + 1 < end)
        doQuickSortLab3 (arr, left + 1, end);
}

void doDecrIncrMultiDivLab3 (int *arr, int order, int value, int action)
{
    int *end = arr + order * order - 1;
    for (int *curr = arr; curr <= end; curr++)
    {
        switch (action)
        {
        case 1:
            *curr -= value;
            break;
        case 2:
            *curr += value;
            break;
        case 3:
            *curr *= value;
            break;
        case 4:
            *curr /= value;
            break;
        }
    }
}

void doPoint1Lab3 (int *arr6, int *arr8, int *arr10, int *order)
{
    int chooseScheme;
    bool choose1Done = 0;
    bool choose2Done = 0;

    while (!(*order == 1 || *order == 2 || *order == 3))
    {
        if (choose1Done)
            cout << "Wrong input!" << endl << endl;
        printPoint1Lab3 (1);
        *order = getch () - 48;
        choose1Done = 1;
        cout << endl;
    }

    while (!(chooseScheme == 1 || chooseScheme == 2))
    {
        if (choose2Done)
            cout << "Wrong input!" << endl << endl;
        printPoint1Lab3 (2);
        chooseScheme = getch () - 48;
        choose2Done = 1;
        cout << endl;
    }

    int *arr = 0;
    switch (*order)
    {
        case 1:
            *order = 6;
            arr = arr6;
            break;
        case 2:
            *order = 8;
            arr = arr8;
            break;
        case 3:
            *order = 10;
            arr = arr10;
            break;
    }

    system ("cls");
    switch (chooseScheme)
    {
        case 1:
            doFill1Lab3 (arr, *order);
            break;
        case 2:
            doFill2Lab3 (arr, *order);
            break;
    }

    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint2Lab3 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint2Lab3 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    int *arr = 0;
    switch (order)
    {
        case 6:
            arr = arr6;
            break;
        case 8:
            arr = arr8;
            break;
        case 10:
            arr = arr10;
            break;
    }

    switch (choose)
    {
        case 1:
            doScheme1Lab3 (arr, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 2:
            doScheme2Lab3 (arr, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 3:
            doScheme3Lab3 (arr, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 4:
            doScheme4Lab3 (arr, order);
            cout << "Changed matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
    }

    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint3Lab3 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint3Lab3 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    int *arr = 0;
    switch (order)
    {
        case 6:
            arr = arr6;
            break;
        case 8:
            arr = arr8;
            break;
        case 10:
            arr = arr10;
            break;
    }

    switch (choose)
    {
        case 1:
            doBubbleSortLab3 (arr, order);
            cout << "Sorted matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 2:
            doShakerSortLab3 (arr, order);
            cout << "Sorted matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 3:
            doCombSortLab3 (arr, order);
            cout << "Sorted matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 4:
            doInsertSortLab3 (arr, order);
            cout << "Sorted matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 5:
            doQuickSortLab3 (arr, arr, arr + order * order - 1);
            cout << "Sorted matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
    }
    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doPoint4Lab3 (int *arr6, int *arr8, int *arr10, int order)
{
    int choose;
    int value;
    bool chooseDone = 0;

    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        printPoint4Lab3 ();
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    int *arr = 0;
    switch (order)
    {
        case 6:
            arr = arr6;
            break;
        case 8:
            arr = arr8;
            break;
        case 10:
            arr = arr10;
            break;
    }

    switch (choose)
    {
        case 1:
            cout << "Enter a value that you want to decrease matrix elements by:" << endl << endl;
            cin >> value;
            doDecrIncrMultiDivLab3 (arr, order, value, choose);
            cout << "New matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 2:
            cout << "Enter a value that you want to increase matrix elements by:" << endl << endl;
            cin >> value;
            doDecrIncrMultiDivLab3 (arr, order, value, choose);
            cout << "New matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 3:
            cout << "Enter a value that you want to multiply matrix elements by:" << endl << endl;
            cin >> value;
            doDecrIncrMultiDivLab3 (arr, order, value, choose);
            cout << "New matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
        case 4:
            value = 0;
            bool valueEntered = 0;

            while (value == 0)
            {
                if (valueEntered)
                    cout << "You can not divide by 0!" << endl << endl;
                cout << "Enter a value that you want to divide matrix elements by:" << endl << endl;
                cin >> value;
                valueEntered = 1;
                cout << endl;
            }

            doDecrIncrMultiDivLab3 (arr, order, value, choose);
            cout << "New matrix:" << endl << endl;
            showMatrixLab3 (arr, order);
            break;
    }

    cout << endl;
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void doIdzLab3 (int *arr6, int *arr8, int *arr10, int order)
{
    int *firstMatrix;
    int secondMatrix [order][order];
    int resultMatrix [order][order];

    switch (order)
    {
        case 6:
            firstMatrix = arr6;
            break;
        case 8:
            firstMatrix = arr8;
            break;
        case 10:
            firstMatrix = arr10;
            break;
    }

    for (int *curr = *secondMatrix; curr < *secondMatrix + order * order; curr++)
        *curr = rand () % order * order + 1;

    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle (STD_OUTPUT_HANDLE);

    system ("cls");
    showMatrixLab3 (*secondMatrix, order);
    Sleep (300);
    destCoord.X = order / 2 * 5;
    destCoord.Y = order * 3 + 1;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << "-";
    cout.flush();
    Sleep (500);

    for (int *curr = firstMatrix; curr < firstMatrix + order * order; curr++)
    {
        destCoord.X = (((curr - firstMatrix) % order) * 5);
        destCoord.Y = (((curr - firstMatrix) / order) * 3 + (3 * order + 5));
        SetConsoleCursorPosition (hStdout, destCoord);
        cout << setw (3) << *curr;
        cout.flush();
    }

    Sleep (300);
    destCoord.X = order / 2 * 5;
    destCoord.Y = 3 * order * 2 + 7;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << "=";
    cout.flush();
    Sleep (500);

    int index = 0;
    for (int *currFirst = firstMatrix, *currSecond = *secondMatrix; currFirst < firstMatrix + order * order; currFirst++, currSecond++)
    {
        index++;
        *(*resultMatrix + index) = *currSecond - *currFirst;
        destCoord.X = (((currFirst - firstMatrix) % order) * 5);
        destCoord.Y = (((currFirst - firstMatrix) / order) * 3 + (3 * order * 2 + 12));
        SetConsoleCursorPosition (hStdout, destCoord);
        cout << setw (3) << *(*resultMatrix + index);
        cout.flush();
        Sleep (300);
    }

    destCoord.X = 0;
    destCoord.Y = 3 * order * 3 + 13;
    SetConsoleCursorPosition (hStdout, destCoord);
    cout << endl;
    cout.flush();
    cout << "Press any button to continue..." << endl << endl;
    getch ();
}

void menuLab3 ()
{
    srand (time(NULL));
    int order;
    int choose;
    bool filled = 0;
    int arr6 [6][6];
    int arr8 [8][8];
    int arr10 [10][10];

    while (true)
    {
        printMenuLab3 ();
        choose = getch () - 48;
        cout << endl;
        if (choose == 6)
            break;
        switch (choose)
        {
            case 1:
                doPoint1Lab3 (*arr6, *arr8, *arr10, &order);
                filled = 1;
                break;
            case 2:
                if (filled)
                    doPoint2Lab3 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 3:
                if (filled)
                    doPoint3Lab3 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 4:
                if (filled)
                    doPoint4Lab3 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            case 5:
                if (filled)
                    doIdzLab3 (*arr6, *arr8, *arr10, order);
                else
                    cout << "Fill the matrix first!!! (point 1)" << endl;
                break;
            default:
                cout << "Wrong input!" << endl << endl;
                break;
        }
    }
}
