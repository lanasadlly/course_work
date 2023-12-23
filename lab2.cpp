#include <iostream>
#include <ctime>
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

void printMenuLab2 ()
{
    cout << "Choose an action" << endl;
    cout << "1 - Create an int array, containing 100 element, each from -99 to 99" << endl;

    cout << "2 - Sort the array. Count time elapsed" << endl;

    cout << "3 - Find maximum and minimum values in the sorted and the unsorted array." << endl;
    cout << "    Count time elapsed" << endl;

    cout << "4 - Print average of maximum and minimum values in the sorted and unsorted array." << endl;
    cout << "    Print indexes of all elements with the same value and the number of them." << endl;
    cout << "    Count time elapsed" << endl;

    cout << "5 - Print a number of elements that are smaller than the entered value in the sorted array" << endl;

    cout << "6 - Print a number of elements that are bigger than the entered value in the sorted array" << endl;

    cout << "7 - Print if the sorted array contains the entered value" << endl;
    cout << "    Release the binary search." << endl;
    cout << "    Compare time elapsed for the binary search and the iterational search" << endl;

    cout << "8 - Change the places of values with entered indexes." << endl;
    cout << "    Count time elapsed" << endl;

    cout << "9 - Replace each element with a sum of this one and the following one" << endl;
    cout << "    (last = last + first)." << endl;
    cout << "    Give each element a random index in the array." << endl;
    cout << "    Print the number of elements that are divided by 1, 2, 3, 4, 5, 6, 7, 8, 9 with no remainder" << endl;

    cout << "0 - Go to another lab" << endl << endl;
}

void doBubbleSortLab2 (int sortedArr [], int N)
{
    int end = N - 1;
    bool swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < end; i ++)
        {
            if (sortedArr [i] > sortedArr [i + 1])
            {
                swap (sortedArr [i], sortedArr [i + 1]);
                swapped = 1;
            }
        }
        end--;
    }
}

void doShakerSortLab2 (int sortedArr [], int N)
{
    bool swapped = 1;
    int end = N - 1;
    int start = 0;

    while (swapped)
    {
        swapped = 0;
        for (int i = start; i < end; i++)
        {
            if (sortedArr [i] > sortedArr [i + 1])
            {
                swap (sortedArr [i], sortedArr [i + 1]);
                swapped = 1;
            }
        }
        end--;
        for (int i = end - 1; i >= start; i--)
        {
            if (sortedArr [i] > sortedArr [i + 1])
            {
                swap (sortedArr [i], sortedArr [i + 1]);
                swapped = 1;
            }
        }
        start++;
    }
}

void doCombSortLab2 (int sortedArr [], int N)
{
    int end = N - 1;
    bool swapped = 1;
    float k = 1.247, step = N - 1;

    while (step >= 1)
    {
        for (int i = 0; i + step < N; i++)
        {
            if (sortedArr [i] > sortedArr [int (i + step)])
                swap (sortedArr [i], sortedArr [int (i + step)]);
        }
        step /= k;
    }

    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < end; i ++)
        {
            if (sortedArr [i] > sortedArr [i + 1])
            {
                swap (sortedArr [i], sortedArr [i + 1]);
                swapped = 1;
            }
        }
        end--;
    }
}

void doInsertSortLab2 (int sortedArr [], int N)
{
    int key, j;

    for(int i = 1; i < N ; i++)
    {
        j = i - 1;
        key = sortedArr [i];
        while (j >= 0 && sortedArr [j] > key)
        {
            sortedArr [j + 1] = sortedArr [j];
            j--;
        }
        sortedArr [j + 1] = key;
    }
}

void doQuickSortLab2 (int sortedArr [], int start, int end)
{
    int left = start;
    int right = end;

    int mid = (start + end) / 2;
    int key = sortedArr [mid];
    int countLess = 0;

    for (int i = start; i <= end; i++)
        if (sortedArr [i] < key)
            countLess += 1;
    swap (sortedArr [mid], sortedArr [start + countLess]);

    while (left <= right)
    {
        while (sortedArr [left] < key)
            left++;
        while (sortedArr [right] >= key)
            right--;
        if (left < right)
        {
            swap (sortedArr [left], sortedArr [right]);
            left++;
            right--;
        }
    }

    if (right > start)
        doQuickSortLab2 (sortedArr, start, right);
    if (left + 1 < end)
        doQuickSortLab2 (sortedArr, left + 1, end);
}

int doBinarySearchLab2 (int arr [], int value, int start, int end, bool flag = 0)
{
    int mid = (start + end) / 2;
    if (end >= start)
    {
        if (arr [mid] == value)
            return mid;
        if (arr [mid] > value)
            return doBinarySearchLab2 (arr, value, start, mid - 1, flag);
        return doBinarySearchLab2 (arr, value, mid + 1, end, flag);
    }
    if (flag == 0)
        return -1;
    else
        return mid;
}

int searchValue (int arr [], int value, int N)
{
    for (int i = 0; i < N; i ++)
    {
        if (arr [i] == value)
            return i;
    }
    return -1;
}

int getMaxi (int arr [], int N)
{
    int maxi = arr [0];

    for (int i = 1; i < N; i++)
    {
        if (arr [i] > maxi)
            maxi = arr [i];
    }
    return maxi;
}

int getMini (int arr [], int N)
{
    int mini = arr [0];

    for (int i = 1; i < N; i++)
    {
        if (arr [i] < mini)
            mini = arr [i];
    }
    return mini;
}

void doPoint1Lab2 (int arr [], int sortedArr [], int N)
{
    cout << "Original array:" << endl;

    for (int i = 0; i < N; i++)
    {
        arr [i] = rand () % 199 - 99;
        sortedArr [i] = arr [i];
        cout << arr [i] << " ";
    }

    cout << endl << endl;
    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doPoint2Lab2 (int arr [], int sortedArr [], int N)
{
    int choose;
    bool chooseDone = 0;

    while (!(choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        cout << "Choose a sorting method:" << endl;
        cout << "1 - bubble sort" << endl;
        cout << "2 - shaker sort" << endl;
        cout << "3 - comb sort" << endl;
        cout << "4 - insert sort" << endl;
        cout << "5 - quick sort" << endl << endl;
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    switch (choose)
    {
    case 1:
        {
        for (int i = 0; i < N; i++)
            sortedArr [i] = arr [i];
        auto start = steady_clock :: now ();
        doBubbleSortLab2 (sortedArr, N);
        auto end = steady_clock :: now ();
        auto elapsed = duration_cast <microseconds> (end - start). count ();
        cout << "Bubble sorting time: " << elapsed << " microseconds" << endl;
        break;
        }
    case 2:
        {
        for (int i = 0; i < N; i++)
            sortedArr [i] = arr [i];
        auto start = steady_clock :: now ();
        doShakerSortLab2 (sortedArr, N);
        auto end = steady_clock :: now ();
        auto elapsed = duration_cast <microseconds> (end - start). count ();
        cout << "Shaker sorting time: " << elapsed << " microseconds" << endl;
        break;
        }
    case 3:
        {
        for (int i = 0; i < N; i++)
            sortedArr [i] = arr [i];
        auto start = steady_clock :: now ();
        doCombSortLab2 (sortedArr, N);
        auto end = steady_clock :: now ();
        auto elapsed = duration_cast <microseconds> (end - start). count ();
        cout << "Comb sorting time: " << elapsed << " microseconds" << endl;
        break;
        }
    case 4:
        {
        for (int i = 0; i < N; i++)
            sortedArr [i] = arr [i];
        auto start = steady_clock :: now ();
        doInsertSortLab2 (sortedArr, N);
        auto end = steady_clock :: now ();
        auto elapsed = duration_cast <microseconds> (end - start). count ();
        cout << "Insert sorting time: " << elapsed << " microseconds" << endl;
        break;
        }
    case 5:
        {
        for (int i = 0; i < N; i++)
            sortedArr [i] = arr [i];
        auto start = steady_clock :: now ();
        doQuickSortLab2 (sortedArr, 0, N - 1);
        auto end = steady_clock :: now ();
        auto elapsed = duration_cast <microseconds> (end - start). count ();
        cout << "Quick sorting time: " << elapsed << " microseconds" << endl;
        break;
        }
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i< N; i++)
        cout << sortedArr [i] << " ";

    cout << endl << endl;
    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doPoint3Lab2 (int arr [], int sortedArr [], int N)
{
    int mini, maxi;

    auto start = steady_clock :: now ();
    maxi = getMaxi (arr, N);
    mini = getMini (arr, N);
    auto end = steady_clock :: now ();
    auto elapsed = duration_cast <microseconds> (end - start). count ();

    cout << "Maximum array value is " << maxi << endl;
    cout << "Minimum array value is " << mini << endl;
    cout << "Time getting minimum and maximum values in an unsorted array:" << endl;
    cout << elapsed << " microseconds" << endl;

    start = steady_clock :: now ();
    maxi = sortedArr [N - 1];
    mini = sortedArr [0];
    end = steady_clock :: now ();
    elapsed = duration_cast <microseconds> (end - start). count ();

    cout << "Time getting minimum and maximum values in a sorted array:" << endl;
    cout << elapsed << " microseconds" << endl << endl;
    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doPoint4Lab2 (int arr [], int sortedArr [], int N)
{
    int maxi, mini, average;
    int number = 0;

    auto start = steady_clock :: now ();
    maxi = getMaxi (arr, N);
    mini = getMini (arr, N);
    average = (maxi + mini) / 2;
    cout << "Average of minimum and maximum values in an unsorted array: " << average << endl;
    cout << "Indexes of elements equal to the average: ";
    for (int i = 0; i < N; i++)
    {
        if (arr [i] == average)
        {
            cout << i << " ";
            number ++;
        }
    }
    auto end = steady_clock :: now ();
    auto elapsed = duration_cast <microseconds> (end - start). count ();

    cout << endl;
    cout << "Number of elements equal to average: " << number << endl;
    cout << "Time of searching in an unsorted array: ";
    cout << elapsed << " microseconds" << endl;

    number = 0;

    start = steady_clock :: now ();
    maxi = sortedArr [N - 1];
    mini = sortedArr [0];
    average = (maxi + mini) / 2;
    cout << "Average of minimum and maximum values in a sorted array: " << average << endl;
    cout << "Indexes of elements equal to the average: ";
    for (int i = 0; i < N; i++)
    {
        if (sortedArr [i] == average)
        {
            cout << i << " ";
            number ++;
        }
    }
    end = steady_clock :: now ();
    elapsed = duration_cast <microseconds> (end - start). count ();

    cout << endl;
    cout << "Number of elements equal to average: " << number << endl;
    cout << "Time of searching in a sorted array: ";
    cout << elapsed << " microseconds" << endl << endl;
    cout << "Press any button to go to menu..." << endl << endl;
    getch ();
}

void doPoint5Lab2 (int sortedArr [], int N)
{
    int border;
    cout << "Enter a value: ";
    cin >> border;

    int index = doBinarySearchLab2 (sortedArr, border, 0, N - 1, 1);
    while (!(sortedArr[index] < border))
        index--;

    cout << "Number of smaller array values: " << index + 1 << endl << endl;
    cout << "Press any button to go continue..." << endl << endl;
    getch ();
}

void doPoint6Lab2 (int sortedArr [], int N)
{
    int border;
    cout << "Enter a value: ";
    cin >> border;

    int index = doBinarySearchLab2 (sortedArr, border, 0, N - 1, 1);
    while (!(sortedArr[index] > border))
        index++;

    cout << "Number of bigger array values: " << N - index << endl << endl;
    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doPoint7Lab2 (int sortedArr [], int arr [], int N)
{
    int value;
    cout << "Enter a value: ";
    cin >> value;

    cout << "Doing binary search..." << endl;
    auto startBinary = steady_clock :: now ();
    if (doBinarySearchLab2 (sortedArr, value, 0, N - 1) > -1)
    {
        cout << value << " is in array with index ";
        cout << doBinarySearchLab2 (sortedArr, value, 0, N - 1) << endl;
    }
    else
        cout << value << " is not in array" << endl;
    auto endBinary = steady_clock :: now ();
    auto elapsedBinary = duration_cast <microseconds> (endBinary - startBinary). count ();
    cout << "Time of binary search: " << elapsedBinary << " microseconds" << endl << endl;

    cout << "Doing iterational search..." << endl;
    auto start = steady_clock :: now ();
    if (searchValue (arr, value, N) > -1)
    {
        cout << value << " is in array with index ";
        cout << searchValue (sortedArr, value, N) << endl;
    }
    else
        cout << value << " is not in array" << endl;
    auto end = steady_clock :: now ();
    auto elapsed = duration_cast <microseconds> (end - start). count ();
    cout << "Time of iterational search: " << elapsed << " microseconds" << endl << endl;

    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doPoint8Lab2 (int arr [], int N)
{
    int first, second;
    cout << "Enter indexes of 2 elements that you want to change places" << endl;
    cout << "(from 0 to " << N - 1 << "):" << endl;
    cin >> first >> second;

    auto start = steady_clock :: now ();
    swap (arr [first], arr[second]);
    auto end = steady_clock :: now ();
    auto elapsed = duration_cast <microseconds> (end - start). count ();
    cout << "Time of changing places: ";
    cout << elapsed << " microseconds" << endl;

    int choose;
    bool chooseDone = 0;

    while (!(choose == 0 || choose == 1))
    {
        if (chooseDone)
            cout << "Wrong input!" << endl << endl;
        cout << "Do you want to see the Changed array?" << endl;
        cout << "Enter '1' for yes and '0' for no" << endl;
        choose = getch () - 48;
        chooseDone = 1;
        cout << endl;
    }

    if (choose == 1)
    {
        cout << "Changed array:" << endl;
        for (int i = 0; i < N; i++)
            cout << arr [i] << " ";
        cout << endl;
    }

    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void doIdzLab2 (int arr [], int N)
{
    int number;
    int swapArr [N];
    int index;

    for (int i = 0; i < N; i++)
        swapArr [i] = arr [i] + arr [(i + 1) % N];

    for (int i = 0; i < N; i++)
    {
        index = rand () % N;
        swap (swapArr [i], swapArr [index]);
    }

    cout << "Changed array:" << endl;
    for (int i = 0; i < N; i++)
        cout << swapArr [i] << " ";
    cout << endl;

    for (int div = 1; div < 10; div++)
    {
        number = 0;
        for (int i = 0; i < N; i++)
            if (swapArr [i] % div == 0)
                number++;
        cout << "Number of elements that are divided by " << div << " with no remainder: " << number << endl;
    }

    cout << endl;
    cout << "Press any button to go to continue..." << endl << endl;
    getch ();
}

void menuLab2()
{
    const int N = 6;
    setlocale (0, "");
    srand (time(NULL));
    int arr [N];
    int sortedArr [N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand () % 199 - 99;
        sortedArr [i] = arr [i];
    }

    bool sorted = 0;
    int choose;

    while (true)
    {
        const int N = 100;
        printMenuLab2 ();
        choose = getch () - 48;
        cout << endl;
        if (choose == 0)
            break;
        switch (choose)
        {
        case 1:
            doPoint1Lab2 (arr, sortedArr, N);
            sorted = 0;
            break;
        case 2:
            doPoint2Lab2 (arr, sortedArr, N);
            sorted = 1;
            break;
        case 3:
            if (sorted)
                doPoint3Lab2 (arr, sortedArr, N);
            else
                cout << "You need to sort the array first! (point 2)" << endl << endl;
            break;
        case 4:
            if (sorted)
                doPoint4Lab2 (arr, sortedArr, N);
            else
                cout << "You need to sort the array first! (point 2)" << endl << endl;
            break;
        case 5:
            if (sorted)
                doPoint5Lab2 (sortedArr, N);
            else
                cout << "You need to sort the array first! (point 2)" << endl << endl;
            break;
        case 6:
            if (sorted)
                doPoint6Lab2 (sortedArr, N);
            else
                cout << "You need to sort the array first! (point 2)" << endl << endl;
            break;
        case 7:
            if (sorted)
                doPoint7Lab2 (sortedArr, arr, N);
            else
                cout << "You need to sort the array first! (point 2)" << endl << endl;
            break;
        case 8:
            doPoint8Lab2 (arr, N);
            break;
        case 9:
            doIdzLab2 (arr, N);
            break;
        default:
            cout << "Wrong input!" << endl << endl;
            break;
        }
    }
}
