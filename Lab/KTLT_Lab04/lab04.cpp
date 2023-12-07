#include <stdio.h>
#include <iostream>
#include <limits>
using namespace std;
#define MAX_SIZE 100
#define MAX_INT 2147483647
#define MIN_INT -2147483648

void input(int array[], int &size)
{
    cout << "Nhap size mang: " << endl;
    cin >> size;
    while (1)
    {
        if (size <= 0 || size > MAX_SIZE)
        {
            cout << "Vui long nhap lai size mang: " << endl;
            cin >> size;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Nhap phan tu " << i << ": ";
        cin >> array[i];
        while (1)
        {

            if (array[i] == MIN_INT || array[i] == MAX_INT)
            {
                cin.clear();
                cin.ignore(1);
                cout << "So vua nhap lon hon INT_MAX hoac nho hon INT_MIN. Nhap lai phan tu " << i << ": ";
                cin >> array[i];
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }
        cout << "Array[" << i << "]: " << array[i] << endl;
    }
}

void output(int array[], int size)
{
    cout << "=========== In cac phan tu cua mang =============" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "]: " << array[i] << endl;
    }
}

int sumEvenElements(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (array[i] % 2 == 0) ? array[i] : 0;
    }
    return sum;
}

int productOddPositionElements(int array[], int size)
{
    int result = 1;
    for (int i = 0; i < size; i++)
    {
        result *= (i % 2 == 1) ? array[i] : 1;
    }
    return result;
}

int main()
{
    int array[MAX_SIZE];
    int size;
    input(array, size);
    output(array, size);
    cout << "======================================" << endl;
    cout << "Tong cac so chan trong mang la:  " << sumEvenElements(array, size) << endl;
    cout << "Tich gia tri co vi tri le trong mang la:  " << productOddPositionElements(array, size) << endl;
}