/*
 ==============================================================================================================================
 Name        : main.cpp
 Author      : Siddhata Patil
 Copyright   : Copyright © InterviewBit for the question.
 Copyright   : Copyright ©  Siddhata Patil. Sourcecode rights reserved.
 Question    : Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 ==============================================================================================================================
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
 vector<vector<int> > combinationSum(vector<int> &A, int target);
}obj;

void MakeAns(int current,int target,vector<int>& path, vector<vector<int> >& result,vector<int>& A)
{
    if(current==A.size())
    {
        if(target==0)
            result.push_back(path);
        return;
    }
    if(target<0)
        return;
    int value = A[current], end = current;
    while(end<A.size() && A[end]==value)
            end++;
    int count = end - current;
    for(int i=0;i<=count;i++)
    {
        MakeAns(end,target,path,result,A);
        path.push_back(value);
        target-=value;
    }

    path.erase(path.begin()+path.size()-count-1,path.end());
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int target)
{
    sort(A.begin(),A.end());
    vector<vector<int> > result;
    vector<int> path;
    MakeAns(0,target,path,result,A);
    return result;
}

int main()
{
  vector<vector<int> >B;
  int A1[7]={10,1,2,7,6,1,5};
  vector<int> A(A1, A1+sizeof(A1)/sizeof(A1[0]));
  B =obj.combinationSum(A, 8);
  cout<<"Given candidate set 10,1,2,7,6,1,5 and target 8, solution set is:"<<endl;
  for (int i = 0; i < B.size(); i++)
  {
    for (int j = 0; j < B[i].size(); j++) cout<<B[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
