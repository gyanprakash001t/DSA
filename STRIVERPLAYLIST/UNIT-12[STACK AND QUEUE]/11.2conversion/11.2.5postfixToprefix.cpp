#include <bits/stdc++.h>
using namespace std;

string postfix_to_prefix(string str)
{
    stack<string> st;
    for (int i = 0; i<str.length(); i++) // 
    {
        if (str.length() < 2) return "Invalid Postfix Expression";
        
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^') // operator
        {
            string top1 = st.top();
            st.pop();
            string top2 =  st.top();
            st.pop();
            string new_top = str[i]+ top2  + top1 ;
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
    string str = "AB-DE+F*/";
    string res = postfix_to_prefix(str);
    cout<<res;


    return 0;
}