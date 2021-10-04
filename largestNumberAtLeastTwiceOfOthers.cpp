//Made by Vivek Arora

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Number of elements in array: " << endl;
    int n;
    cin >> n;

    cout << "Enter elements: " << endl;

    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int maximum1 = 0, maximum2 = 0, idxOfMaximum1 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > maximum1)
        {
            maximum2 = maximum1;
            maximum1 = a[i];
            idxOfMaximum1 = i;
        }
        else if (a[i] > maximum2)
        {
            maximum2 = a[i];
        }
    }
    cout<<"Answer is: "<<endl;
    if (maximum1 >= 2*maximum2)
    {
        cout << idxOfMaximum1 << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}
