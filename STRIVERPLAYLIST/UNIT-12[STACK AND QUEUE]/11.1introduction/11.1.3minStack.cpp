#include <bits/stdc++.h>
using namespace std;

// it will have  SC :O(2n), TC:O(1)

// Brute

class minStack
{
    stack<pair<int, int>> st;

    void push(int x)
    {
        if (st.empty())
        {
            st.push({x, x});
        }
        else
        {
            st.push({x, min(x, st.top().second)});
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

// optimal
// SC :O(N), TC:O(1)

class minStack2
{
    stack<int> st;
    int minm = INT_MAX;

    void push(int val)
    {
        if(st.empty())
        {
            st.push(val); 
            minm = val;
        }
        else
        {
            if(val>minm) 
                st.push(val);
            else 
                st.push(2*val- minm);
                minm =val;


        }
    }
    int getMin()
    {
        return minm;
    }
    int top()
    {
        int x = st.top();
        if(x<minm) 
            return minm ; // cause minm is top in this case
        else
            return x;
    }

    void pop()
    {
        int x = st.top();
        st.pop();
        if(x <minm) // x was modified value i.e. (2*val- minm)
        {
            minm = 2*minm -x;
        }
    }
};

int main()
{

    return 0;
}
