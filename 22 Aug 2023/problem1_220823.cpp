#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[n];
    int arr[100000] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[nums[i]]++;
    }

    for (int i = 0; i < 100000; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else
        {
            for (int j = 0; j < arr[i]; j++)
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}
