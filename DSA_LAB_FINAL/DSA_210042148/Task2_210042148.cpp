#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isProperlyParenthesized(string &expression)
{
    stack<char> bracketStack;

    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];

        if (c == '(' || c == '[' || c == '{')
        {
            bracketStack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (bracketStack.empty())
            {
                return false;
            }

            char top = bracketStack.top();
            bracketStack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return bracketStack.empty();
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string expression;
        getline(cin, expression);

        if (isProperlyParenthesized(expression))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}