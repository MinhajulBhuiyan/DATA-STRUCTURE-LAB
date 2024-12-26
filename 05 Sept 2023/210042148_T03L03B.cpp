#include <iostream>
#include <string>

using namespace std;

string removeLetters(string input)
{
    string result;

    for (int i = 0; i < input.length(); i++)
    {
        char currentChar = input[i];

        // If the result is not empty and the current character is equal to the last character in the result
        if (!result.empty() && currentChar == result.back())
        {
            result.pop_back(); // Remove the last character from the result
        }
        else
        {
            result.push_back(currentChar); // Otherwise, add the current character to the result
        }
    }

    return result;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        string result = removeLetters(input);
        cout << "[" << result << "]" << endl;
    }

    return 0;
}
