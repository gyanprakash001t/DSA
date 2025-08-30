#include <bits/stdc++.h>
using namespace std;

void printSubsequences(vector<int>& arr, int index, vector<int>& current)
 {
    // Base case: if we have processed all elements
    if (index == arr.size())
    {
        if (current.empty()) 
        {
            cout << "{}"; // empty subsequence
        } 
        else 
        {
            for (int x : current) cout << x << " ";
        }
        cout << endl;
        return;
    }

    // Choice 1: include arr[index]
    current.push_back(arr[index]);
    printSubsequences(arr, index + 1, current);

    // backtrack (remove the element)
    current.pop_back();

    // Choice 2: exclude arr[index]
    printSubsequences(arr, index + 1, current);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> current;

    cout << "All subsequences:\n";
    printSubsequences(arr, 0, current);

    return 0;
}
