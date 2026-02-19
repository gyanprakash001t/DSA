#include<bits/stdc++.h>
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

void reverse_for_prefix(string &str)
{
    // reverse the string 
    reverse(str.begin(), str.end());
    // replace the opening with closing and closing with opening
    int i=0;
    while(i<str.length())
    {
        if(str[i] ==')')
        {
            str[i]='(';
        }
        else if(str[i] =='(')
        {
            str[i]=')';
        }
        i++;
    }
    
}

string intfix_to_prefix(string &str)
{
    // step 1: reverse the  infix expression
    reverse_for_prefix(str);

    //step 2:
    // controlled conversion to postfix
    // if it's operator or parenthesis keep pushing 
    // the moment you scan a closing parenthesis keep popping and appending to answer until you encounter opening parenthesis 
    // at the ens pop all and append to  the answer 
    int i=0;
    stack<char>st;
    string ans="";
     int n = str.length();
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
            if(str[i]=='^')
            {
                while(!st.empty() && (prec(str[i])<= prec(st.top()))) // basically you can't store two exponent operators in the stack together
                {
                    ans = ans+st.top(); 
                    st.pop();
                }
            }
            else
            {
                while(!st.empty() && (prec(str[i])< prec(st.top()))) // if priority is same they it will be pushed unlike infix to postfix  where in case of similar we used to  pop
                {
                    ans += st.top();
                    st.pop();
                }

            }
            st.push(str[i]);
        }
        i++;
    }  
    // if anything left in the stack append to the ans 
    
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // reverse the ans to get final answer(postfix expression)
    reverse(ans.begin(), ans.end());
    return ans;

}