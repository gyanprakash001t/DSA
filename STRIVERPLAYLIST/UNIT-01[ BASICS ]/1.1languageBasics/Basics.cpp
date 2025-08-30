/*  in this section we'd learn about data types, conditional statements ,loops , little idea  about time and space complexity then we'll solve some problems to print the patterns after that we'll lern stl .... after STL we'll learn ,basic mathematics ,basics of recursion and little about  hashmaps  these will be the  basics understanding of c++ language and this will be sort of revision for c++.......
this file will be revision to c++ STL and rest of the previous topics (conditional statements, loops, time and space compexity) are there in the demo.cpp file */



//  it's video-06

#include <bits/stdc++.h>
using namespace std;

//we can define functions here and use them in the main function
void Print (){
    cout<<"Ram \n";
}

// pair
void explainPairs(){
    pair<int, int>p {1,3};
    cout<<p.second<<" "<<p.first<<endl;

   //nested pair
    pair<int,pair<int,int>>q= {3,{4,5}};
    cout<<q.first<<" " <<q.second.second<<endl;

    // declaring an array of pair type
     pair<int, int >arr[]={{1,2},{2,3},{5,6}};
     cout<<arr[1].second<<endl;
}

//vector

void explainVectors(){
//initiate a vector
vector<int>v; // Initiate an empty vector of integers
vector<int>newMethodToInitiate  (5);// initates a vector of size 5 where each instance maybe 0 or some other garbage value    
vector<int>v2 (5,100);  //initiated a vectors of 5 integrs each iniitated with 100
vector<int>v3={1,2,3,4};  // initiate a vector using a initializer list ;

// above are the different methods to initiate a  vector
v.push_back(1);  //
v.emplace_back(2);
/* difference between push_back  and emplace_back
push_back() and emplace_back() are functions used to add elements to the end of a vector

int main() {
    vector<string> v;
    string name = "Shahrukh";
    v.push_back(name); // Adds a copy of 'name'
    v.push_back("Khan"); // Creates a temporary string and pushes it

    for (auto s : v) cout << s << " ";
    return 0;
}

✅ Rule of thumb:
Use emplace_back() when you're creating a new object directly inside the vector.

Use push_back() when you're adding an already-created object.

*/

vector<pair<int, int>>v4;
v4.push_back({4,5});
v4.emplace_back(6,7); 

// we can also pass a vector in to another vector
vector<int>v5(v2); // v5 will be a copy of vector  v2 initially it will looks similar to what v2 but whatever operation we gonna perform on v2 it doesn't gonna affect v5 cause it's the copy of the v2 ..either you remove or add any  new element  

// accessing the elements of vector

// access similar to array
cout<<v2[0];  
cout<<v2.at(0);  // this is not prefereable 
cout<<v2.back();  // back function returns the reference of the last element in the vector and it is useful when we need to modify the last element int the vector
cout<<"\n";



// iterator method 
// 1.Declare the  iterator
// 2.The iterator points to the beginning of the vector
// The type "vector<int>::iterator" is used to declare an iterator that can traverse through the vector.
// v3.begin() returns an iterator pointing to the first element, and v3.end() returns an iterator that points just past the last element.


for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it) {    // end poins to memory location just next to the last element in the vector
    // Dereference the iterator to access the element
    cout << *it << " ";
}
cout<<"\n";


// in STL there is also a shortcut to initiate the iterator i.e. "auto" which automatically assign the  data type to the variable according to the assigned data
for (auto it = v3.begin(); it != v3.end(); ++it) {  
    // Dereference the iterator to access the element
    cout << *it << " ";
}
cout<<"\n";

// printing the vecotr using for each loop

for (auto it : v3) {
    cout << it << " ";
}  
cout<<"\n";

/* The syntax for (auto num : numbers) iterates over each element in the vector. The auto keyword lets the compiler deduce the type of num (which is int in this case).
Element Access:
In each iteration, the current element is stored in num and then printed. */


// now we'll learn about deletion of elements fron vector
//you can directly pas  the address to the begin function
v3.erase(v3.begin()+1);  //    it deletes the second element from v3 and then vector will be reshuffled  
cout<<"this is the  vector after updation1 \n";
for (auto it : v3) {
    cout << it << " ";
}  
cout<<"\n";

v3.erase(v3.begin()+1);  // deletes the second element from v3
cout<<"this is the  vector after  updation2 \n";
for (auto it : v3) {
    cout << it << " ";
} 

// insertion of elements in the vector
 vector<int> v9(2,100); //{100,100}
v9.insert(v9.begin(),300); //{300,100,100}

//vector_name.insert(position_iterator, count, value);
/* 
 Parameter          	Meaning

 v9.begin() + 1	        Iterator pointing to position 1 (second element)
 2	                    Number of times to insert the value
 10	                    The value to insert 

 */

v9.insert(v9.begin()+1,2,10); //{300,10,10,100,100} 
//insertion of a vector  
vector <int> copy(2,50);
v9.insert(v9.begin(), copy.begin(), copy.end());  //{50,50,300,10,10,100,100}

//Explore some member functions 


cout<<"size of v9 vector is : " <<v9.size()<<"\n";
v9.swap(copy);
cout <<"the updated v9 vector after swapping is " <<endl;
for(auto it :v9){
    cout<<it<<" ";

}
cout<<"\n";
cout <<"the updated copy vector after swapping is " <<endl;
for(auto it :copy){
    cout<<it<<" ";

}



v9.clear();// clears the entire vector
cout<<"\n";
cout<< "is v9 gets empty after performing clear operation on the vector :  ";
cout<<v9.empty ()<<endl ; // return true or flase bassed on the number of elements


}


// list
 void explainList(){
    list<int> ls;
    ls.push_back(2); //{2}
    ls.emplace_back(5); //{2,5}
    // these push_font and  emplace_front is major differentiator function
    ls.push_front(11);
    ls.emplace_front(887);
    // rest  functions are same as in the vector 
    cout <<"the list is : ";
    for(auto it:ls){
        cout<<it<<" ";
    }
 }

void explainDeque(){
    // similar to list and vector

}

void explainStack(){
    // it follows the LIFO (Last in first out) principle
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.emplace(6);

    //3 major function push, pop , top

    cout<<st.top();
      
}

void explainQueue(){
    // it follows the  FIFO  principal
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);

    q.back() += 5; // this will return 9 cause it follows FIFO principle 
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;

    // rest of the functions are similar to the stack

}

void explainPriorityQueue(){

    // max heap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(5);
    pq.push(8);
    pq.emplace(10);
    cout<<pq.top();
     

     // you can explore more on these after learning tree DS  ... it arranges the data onthe priority basis or larger  first

     // in order to store the minimum data on the  top  you need to follow the below syntax
     // generally known as min heap
     priority_queue<int, vector<int>, greater<int>>pq;

    pq.push(1);
    pq.push(565);
    pq.push(864);
    pq.emplace(1032);
    cout<<pq.top(); //  will return  1(least priority)
}

void explainSet(){
    // stores in the sorted and unique only...
}





//main function

int main(){
    Print();
    explainPairs();
    explainVectors();
    explainList();
    explainStack();
    return 0;

}

