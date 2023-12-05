#include <stdio.h>
#include <iostream>
#include <map>
#include <list>
#define Extream -1
using namespace std;

unsigned long long computeIncomeTax(int L, int R, float tax, unsigned long long salary)
{
    unsigned long long income_tax = 0;
    L *= 1000000;
    R *= 1000000;
    if (salary < L)
        return income_tax;
    else
    {
        if (salary < R || R == Extream)
            income_tax = (salary - L) * tax;
        else
            income_tax = (R - L) * tax;
    }
    return income_tax;
}

int main()
{
    unsigned long long salary;
    unsigned long long income_tax = 0;
    cout << "Nhap luong: ";
    cin >> salary;
    while (salary < 0)
    {
        cout << "Muc luong khong the < 0. Vui long nhap lai: ";
        cin >> salary;
    }
    list<list<int>> rankSalary = {
        {0, 4},
        {4, 6},
        {6, 9},
        {9, 14},
        {14, 24},
        {24, 44},
        {44, 84},
        {84, -1}};
    list<float> tax = {0.0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35};

    for (auto pair : rankSalary)
    {
        income_tax += computeIncomeTax(pair.front(), pair.back(), tax.front(), salary);
        tax.pop_front();
    }
    cout << "Thue phai dong: " << income_tax << endl;
}