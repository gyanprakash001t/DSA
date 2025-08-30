#include <bits/stdc++.h>
using namespace std;

vector<int> merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left < mid + 1 && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    return temp;
}

vector<int> mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    return merge(arr, low, mid, high);
}

int main()
{
    int arr[] = {3, 1, 2, 4, 5, 1, 2, 6, 4};
    mergeSort(arr, 0, 9);
    void printArray(int arr[]);
    {
        for (int i = 0; i < 9; i++)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
