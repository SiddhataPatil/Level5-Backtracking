/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given a collection of numbers, return all possible permutations
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
 vector<vector<int> > permute(vector<int> &num);
}obj;

vector< vector<int> > g;

void func(vector<int> A,int start,int r)
{
    if (start == r)
     g.push_back(A);
    else
    {
       for (int i = start; i <= r; i++)
       {
          int temp=A[start]; A[start]=A[i]; A[i]=temp;
          func(A, start+1, r);
          temp=A[start];
          A[start]=A[i]; 
          A[i]=temp; //backtrack
       }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A)
{
    g.clear();
    vector< vector<int> > result;
    func(A,0,A.size()-1);
    result=g;
    return g;
}
int main()
{
  vector<vector<int> >B;
  int A1[3]={1,2,3};
  vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  B =obj.permute(A);
  cout<<"Given set A1[3]={1,2,3} All the permutations are as follows :"<<endl;
  for (int i = 0; i < B.size(); i++)
  {
    for (int j = 0; j < B[i].size(); j++) cout<<B[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
