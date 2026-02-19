
#include <bits/stdc++.h>
using namespace std;

// implement stack using  arrays
class Stack
{
  int size;
  int *arr; // pointer to an integer
  int top;   // index of the top element

public:
  Stack()
  {
    top = -1;
    size = 1000;
    arr = new int[size]; // --> This dynamically allocates an array of size capacity on the heap
    // new returns a pointer to the first element of the array.
  }

  // Destructor
  //Important: Because it’s dynamic memory, you should delete it when done to avoid memory leaks
  ~Stack() 
  {
    delete[] arr;
  }


  void push(int x)
  {
    top++;
    arr[top] = x;
  }

  int pop()
  {
    int x = arr[top];
    top--;
    return x;
  }

  int Top()
  {
    return arr[top];
  }

  int Size()
  {
    return top + 1;
  }
};

// implement queue using arrays
class Queue
{
  int *arr;
  int start, end, currSize, maxSize;

public:
  Queue()
  {
    arr = new int[16];
    start = -1;
    end = -1;
    currSize = 0;
  }

  Queue(int maxSize)
  {
    (*this).maxSize = maxSize;
    arr = new int[maxSize];
    start = -1;
    end = -1;
    currSize = 0;
  }

  void push(int newElement)
  {

    if (currSize == maxSize)
    {
      cout << "Queue is full\nExiting..." << endl;
      exit(1);
    }

    if (end == -1)
    {
      start = 0;
      end = 0;
    }
    else
    {
      end = (end + 1) % maxSize;
      arr[end] = newElement;
      cout << "The element pushed is " << newElement << endl;
      currSize++;
    }
  }

  int pop()
  {
    if (start == -1)
    {
      cout << "Queue Empty\nExiting..." << endl;
    }
    int popped = arr[start];
    if (currSize == 1)
    {
      start = -1;
      end = -1;
    }
    else
    {
      start = (start + 1) % maxSize;
      currSize--;
    }
    return popped;
  }

  int top()
  {
    if (start == -1)
    {
      cout << "Queue is Empty" << endl;
      exit(1);
    }
    return arr[start];
  }

  int size()
  {
    return currSize;
  }
};

// implementation of stack using linkedList

int main()
{

  return 0;
}
