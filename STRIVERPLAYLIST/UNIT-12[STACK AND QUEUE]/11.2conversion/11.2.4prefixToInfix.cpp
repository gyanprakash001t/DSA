#include <bits/stdc++.h>
using namespace std;

string prefix_to_infix(string str)
{
    stack<string> st;
    for (int i = str.length()-1; i>=0; i--) // similar to postfix to infix but we'll start  traversing from right 
    {
        if (str.length() < 2) return "Invalid Postfix Expression";
        
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^') // operator
        {
            string top1 = st.top();
            st.pop();
            string top2 =  st.top();
            st.pop();
            string new_top = '(' + top1 + str[i] + top2 + ')';
            st.push(new_top);
        }
        else  // operand
        {
            string top(1, str[i]);  // convert char → string
            st.push(top);
        }
    }
    return st.top();
}

int main()
{
    string str = "*+PQ-MN";
    string res = prefix_to_infix(str);
    cout<<res;


    return 0;
}