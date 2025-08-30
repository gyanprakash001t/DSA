 #include<bits/stdc++.h>
 using namespace std;

 struct ListNode
 {
    int data;
    ListNode* next;

    ListNode(int  val):data(val),next(nullptr){}
 };

 // brute-->you will keep on storing the value on a data structure[hashmaps] 
 //  then while pushing every value you will check in map if  it's already present then return true other wise keeep pushing until the end

bool  hasCycleM1(ListNode* head)
{
    unordered_map<ListNode* , int>mpp;
    ListNode* temp = head;
    while(temp!=nullptr)
    {
        
        if( ! mpp[temp])
        {
            return true;
        }
        else
        {
          mpp[temp]= 1;
          temp = temp->next;
        }
    }
    return false;
}


 bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow= slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;

        }
        return false;
        
    } 

    int main()
    {   
        
        return 0;
    }