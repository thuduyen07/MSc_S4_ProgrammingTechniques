#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;
int main()
{
    int amount;
    int count;
    int denominations[6] = {500000, 200000, 100000, 50000, 20000, 10000};
    cout << "Nhap so tien: ";
    cin >> amount;
    
    if (amount % 10000 == 0)
    {
        string result = to_string(amount) + " = ";
        for (int i = 0; i < 6; i++)
        {
            if (amount >= denominations[i])
            {
                count = amount / denominations[i];
                amount = amount % denominations[i];
                result += to_string(count) + "x" + to_string(denominations[i]) + "+";
            }
            else{
                result += "0x" + to_string(denominations[i]) + "+";
            }
        }
        result.pop_back();
        cout << result << endl;
    }
    else
    {
        cout << "Vui long nhap so tien la boi so cua 10,000" << endl;
    }
}