#include <stdio.h>
#include <iostream>
using namespace std;

#define Vadidate_K(k, n) ((k >= 1) && (k <= n)) ? true : false;
#define Vadidate_N(n) (n >= 1) ? true : false;

int factorial(int number);
void validateInputVarables(int &k, int &n);
float combination(int k, int n);

int factorial(int number)
{
    if (number == 1 || number == 0)
    {
        return 1;
    }
    return number * factorial(number - 1);
}

void validateInputVarables(int &k, int &n)
{
    bool check_k = Vadidate_K(k, n);
    bool check_n = Vadidate_N(n);
    while (!check_k || !check_n)
    {
        if (!check_k)
        {
            cout << "Please insert k again (1<= k <=n)" << endl;
            cin >> k;
            check_k = Vadidate_K(k, n);
        }
        if (!check_n)
        {
            cout << "Please insert n again (n >= 1)" << endl;
            cin >> n;
            check_n = Vadidate_N(n);
        }
    }
}

float combination(int k, int n)
{
    validateInputVarables(k, n);
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    int k, n;
    cout << "Input k: " << endl;
    cin >> k;
    cout << "Input n: " << endl;
    cin >> n;
    float result = combination(k, n);

    cout << "k-combinations of an n-set is: " << result << endl;
    return 0;
}