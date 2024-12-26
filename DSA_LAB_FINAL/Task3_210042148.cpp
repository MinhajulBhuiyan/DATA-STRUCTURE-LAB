#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int v[n];
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if (s=="null")
        {
            v[i]=INT32_MAX;
        }
        else
        {
            v[i] = stoi(s);
        }
        
        
    }
     
    for (int i = 0; i < n/2; i++)
    {
        int parent = v[i];
        int left = v[2 * i + 1];
        int right = v[2 * i + 2];
        if (2 * i + 1 > n-1)
        {
            break;
        }
        else
        {
            if (left!=INT32_MAX && parent < left)
            {
                flag = false;
                break;
            }
        }
        if (2 * i + 2 > n-1)
        {
            break;
        }
        else
        {
            if (right!=INT32_MAX&&parent > right)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }

    return 0;
}
    