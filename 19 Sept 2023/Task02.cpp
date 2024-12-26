#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> cookies;

    for (int i = 0; i < n; i++)
    {
        int sweetness;
        cin >> sweetness;
        cookies.push(sweetness);
    }

    int count = 0;

    while (!cookies.empty() && cookies.top() < k)
    {
        int minSweet_1 = cookies.top();
        cookies.pop();
        if (!cookies.empty())
        {
            int minSweet_2 = cookies.top();
            cookies.pop();

            int combined_sweetness = minSweet_1 + 2 * minSweet_2;
            cookies.push(combined_sweetness);

            count++;
        }
        else
        {
            break;
        }
    }

    if (!cookies.empty() && cookies.top() < k)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << count << endl;
    }


    return 0;
}
