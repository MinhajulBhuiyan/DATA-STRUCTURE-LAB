#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> numbers;

        while (true)
        {
            int num;
            cin >> num;

            if (num == -1)
            {
                break;
            }

            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end(), greater<int>());

        int result = 0;

        for (int i = 0; i < numbers.size(); i++)
        {
            result = abs(numbers[i] - result);
        }

        cout << result << endl;
    }

    return 0;
}
