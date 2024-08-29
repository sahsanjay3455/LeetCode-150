#include<bits/stdc++.h>
class Solution {
public:
int arr[301][11];

int solve(vector<int>&jd,int n,int idx,int d)
{
    if(d==1)
    {
        return *max_element(begin(jd)+idx,end(jd));
    }
    if(arr[idx][d]!=-1)
    {
        return arr[idx][d];
    }
    int maxi=INT_MIN;
    int result=INT_MAX;
    for(int i=idx;i<=n-d;i++)
    {
        maxi=max(maxi,jd[i]);
        result=min(result,maxi+solve(jd,n,i+1,d-1));
    }

    return arr[idx][d]=result;

}
    int minDifficulty(vector<int>&jd, int d) 
    {
        int n=jd.size();
        if(n<d)
        {
            return -1;
        }
        memset(arr,-1,sizeof(arr));
        return solve(jd,n,0,d);
        
    }
};