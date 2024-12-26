#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int N, Q;
        cin >> N >> Q;

        vector<int> A(N);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        cout << "Case " << t+1 << ":" << endl;

        for (int q = 0; q < Q; q++)
        {
            int op, x, y;
            cin >> op;

            if (op == 1)
            {
                cin >> x >> y;
                for (int i = 0; i < N; i++)
                {
                    if (A[i] == x)
                    {
                        A[i] = y;
                    }
                }

                cout << "{";
                for (int i = 0; i < N; i++)
                {
                    cout << A[i] << " ";
                }
                cout << "}" << endl;
            }
            else if (op == 2)
            {
                cin >> x;
                cout << A[x - 1] << endl;
            }
        }
    }

    return 0;
}
