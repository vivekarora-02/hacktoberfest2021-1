//Made by Vivek Arora

#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

int lcs(char *X, char *Y, int m1, int m2)
{
    if (m1 == 0 || m2 == 0)
    {
        return 0;
    }
    if (X[m1 - 1] == Y[m2 - 1])
    {
        return 1 + lcs(X, Y, m1 - 1, m2 - 1);
    }
    else
    {
        return max(lcs(X, Y, m1, m2 - 1), lcs(X, Y, m1 - 1, m2));
    }
}

int main()
{
    char X[100];
    char Y[100];

    cout << "Enter 1st string: " << endl;
    cin >> X;
    cout << "\nEnter 2nd string: " << endl;
    cin >> Y;

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is: " << lcs(X, Y, m, n);

    return 0;
}
