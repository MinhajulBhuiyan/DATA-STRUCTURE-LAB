#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isProperlyParenthesized(const string &expression)
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
/*Certainly! Let's break down the code for checking balanced parentheses step by step:

1. We iterate through the characters of the `expression` string one by one using a for loop.

2. Inside the loop, we check if the current character `c` is a closing bracket, which can be one of the following: `')'`, `']'`, or `'}'`.

3. If `c` is a closing bracket, we perform the following checks:
   - First, we check if the `bracketStack` (our stack to keep track of opening brackets) is empty.
   If it's empty, it means there is no matching opening bracket for the current closing bracket,
   which is an error. In this case, we return `false` to indicate that the parentheses are not properly balanced.

   - If the `bracketStack` is not empty, we proceed to the next checks.

   - We retrieve the top element from the `bracketStack` using `bracketStack.top()` and store it in the variable `top`.
   This `top` character should be the corresponding opening bracket for the current closing bracket `c`.

   - We then pop (remove) the top element from the `bracketStack` because it has been successfully matched with a closing bracket.

   - Finally, we check if the current closing bracket `c` and the `top` character do not match as per the rules of opening and closing brackets. For example, `')'` should match with `'('`, `']'` should match with `'['`, and `'}'` should match with `'{'`. If they don't match, it indicates a mismatched pair of parentheses, and we return `false`.

4. If the loop completes without any issues and the `bracketStack` is empty, it means all opening and closing brackets have been properly matched. In this case, we return `true` to indicate that the parentheses are properly balanced.

This code uses a stack to keep track of opening brackets and checks if the corresponding closing brackets match when encountered. If there are any mismatches or if there are extra closing brackets without matching opening brackets, the function returns `false`, indicating that the parentheses are not balanced. Otherwise, it returns `true`.*/