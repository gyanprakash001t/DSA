#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')  // highest precedence
        return 3;  
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infix_to_postfix(string str)
{
    int n = str.length();
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < n)
    {
        // if you encounter any operand  then push it in to the stack
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            ans = ans + str[i];
        }
        else if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')') /// you have to pop til you encounter opening bracket
        {
            while (st.empty() || st.top() != '(')
            {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else //   if operator is scanned
        {
            while (!st.empty() && prec(str[i]) <= prec(st.top()))  // if precedence is lower then pop till  you get the top with lower precedence or empty stack
            {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]); // if precedence is greater then push
        }
        i++;
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
