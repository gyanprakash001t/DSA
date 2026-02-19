#include <bits/stdc++.h>
using namespace std;

string prefix_to_postfix(string str)
{
    stack<string> st;
    for (int i = str.length()-1; i>=0; i--) 
    {
        if (str.length() < 2) return "Invalid prefix Expression";
        
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^') // operator
        {
            string top1 = st.top();
            st.pop();
            string top2 =  st.top();
            st.pop();
            string new_top =  top1  + top2 +str[i];
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
    string str = "/-AB*+DEF";
    string res = prefix_to_postfix(str);
    cout<<res;


    return 0;
}