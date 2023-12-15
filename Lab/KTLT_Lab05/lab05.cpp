#include <stdio.h>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

struct PHANSO
{
    float tu, mau;

    // Hàm tìm ước chung lớn nhất (greatest common divisor)
    int UCLN(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void rutGon()
    {
        int ucln = UCLN(tu, mau);
        this->tu = tu / ucln;
        this->mau = mau / ucln;
    }

    PHANSO operator+(PHANSO b)
    {
        PHANSO t;
        t.tu = (this->tu * b.mau + b.tu * this->mau);
        t.mau = this->mau * b.mau;
        t.rutGon();
        return t;
    }

    PHANSO operator-(PHANSO b)
    {
        PHANSO t;
        b.mau = -b.mau;
        t = this->operator+(b);
        t.rutGon();
        return t;
    }

    PHANSO operator*(PHANSO b)
    {
        PHANSO t;
        t.tu = this->tu * b.tu;
        t.mau = this->mau * b.mau;
        t.rutGon();
        return t;
    }

    PHANSO operator/(PHANSO b)
    {
        PHANSO t;
        if (b.tu != 0)
        {
            PHANSO temp;
            temp.tu = b.mau;
            temp.mau = b.tu;
            // float temp = b.tu;
            // b.tu = b.mau;
            // b.mau = temp;
            t = this->operator*(b);
        }
        else
        {
            cout << "tu phai khac khong";
            return {0, 1};
        }
        t.rutGon();
        return t;
    }

    bool operator==(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu == b.tu && this->mau == b.mau ? true : false;
    }

    bool operator!=(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu != b.tu || this->mau != b.mau ? true : false;
    }

    bool operator>=(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu * b.mau >= b.tu * this->mau ? true : false;
    }

    bool operator<=(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu * b.mau <= b.tu * this->mau ? true : false;
    }

    bool operator>(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu * b.mau > b.tu * this->mau ? true : false;
    }

    bool operator<(PHANSO b)
    {
        this->rutGon();
        b.rutGon();
        return this->tu * b.mau < b.tu * this->mau ? true : false;
    }
    stringstream print_PhanSo()
    {
        stringstream s;
        s << fixed << setprecision(1) << this->tu << "/" << this->mau;
        return s;
    }
};

PHANSO findLargestElement(PHANSO array[], int size)
{
    PHANSO largest_element = {0, 1};
    if (size >= 1)
    {
        largest_element = array[0];
        for (int i = 1; i < size; i++)
        {
            if (array[i].operator>(largest_element))
            {
                largest_element = array[i];
            }
        }
    }
    else
    {
        cout << "So phan tu cua mang phai lon hon 0" << endl;
    }
    return largest_element;
}

PHANSO sumElements(PHANSO array[], int size)
{
    PHANSO sum = {0, 1};
    if (size >= 1)
    {
        sum = array[0];
        for (int i = 1; i < size; i++)
        {
            sum = sum.operator+(array[i]);
        }
    }
    else
    {
        cout << "So phan tu cua mang phai lon hon 0" << endl;
    }
    return sum;
}

void sortArray(PHANSO array[], int size)
{
    if (size >= 1)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (array[i].operator>(array[j]))
                {
                    PHANSO temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    else
    {
        cout << "So phan tu cua mang phai lon hon 0" << endl;
    }
}

void printArray(PHANSO array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Array[" << i << "]: " << array[i].print_PhanSo().str() << endl;
    }
}

int main()
{

    PHANSO a = {1.0, 2.0};
    PHANSO b = {2.0, 4.0};
    PHANSO array[] = {{1.0, 8.0}, {2.0, 7.0}, {3.0, 6.0}, {4.0, 5.0}, {5.0, 4.0}, {6.0, 3.0}, {7.0, 2.0}};

    cout << "Mang la: " << endl;
    printArray(array, 7);
    cout << "Phan so lon nhat trong mang la: " << findLargestElement(array, 7).print_PhanSo().str() << endl;
    cout << "Tong cac phan tu trong mang la: " << sumElements(array, 7).print_PhanSo().str() << endl;
    cout << "Mang sau khi duoc sap xep trong mang la: " << endl;
    sortArray(array, 7);
    printArray(array, 7);
}