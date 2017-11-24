/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 Example     : I
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  vector<int > grayCode(int A);
}obj;


vector<int > Solution::grayCode(int A)
{
  vector<int> result;
  result.push_back(0);
  for(int i =0; i < A; i++)
  {
     int size = result.size();
     for(int j = size-1; j >=0; j--)
     {
         result.push_back(result[j]+size);
     }
  }
 return result;
}
int main()
{
  vector<int>B;
  B =obj.grayCode(2);
  cout<<"Gray code sequence for 2 :"<<endl;
  for (int i = 0; i < B.size(); i++)
  {
    cout<<B[i]<<endl;
  }
  return 0;
}
