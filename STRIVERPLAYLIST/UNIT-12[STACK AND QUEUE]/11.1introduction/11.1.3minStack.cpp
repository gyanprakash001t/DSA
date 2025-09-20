#include<bits/stdc++.h>
using namespace std;

// it will have  SC :O(2n)
// Brute

class minStack
{
    stack<pair<int,int>>st;

    void push(int x)
    {
        if(st.empty())
        {
            st.push({x,x});
        }
        else
        {
            st.push({x,min(x,st.top().second)});
        }
    }
    int getMin()
    {
        return st.top().second;
    }
    int top()
    {
        return st.top().second;
    }

    void pop()
    {
       st.pop();
    }

};

int main()
{

    return 0;
}

