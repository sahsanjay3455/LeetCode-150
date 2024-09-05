class Solution {
public:
int fun(vector<int>&dp,int n )
{
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];
    int first=fun(dp,n-1);
    int second=fun(dp,n-2);
    return dp[n]=(first+second);
    
}
    int climbStairs(int n)
    {
      vector<int>d(n+1,-1);
      return fun(d,n);
     
        
    }
};