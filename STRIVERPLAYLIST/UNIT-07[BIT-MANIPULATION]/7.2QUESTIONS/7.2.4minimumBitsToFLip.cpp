    
    #include<bits/stdc++.h>
    using namespace std;

    // brute 
    // convert both the numbers in to  binary  and then  comaper each bit   and can count the number of  bits;

    
    // optimised
    int minBitFlips(int start, int goal) {
        int n = start^goal; // indexes which needs to be flipped are set to 1
        int cnt=0;
        while(n!=0)   // now count the number of 1s
        {
            n= (n) & (n-1);
            cnt++;
        }
        return cnt;
        
    }

    int main()
    {
        int res = minBitFlips(13 ,7);
        cout<<res;
        return 0;
    }