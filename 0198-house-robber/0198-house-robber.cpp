class Solution {
public:
int solve(vector<int>&dp,vector<int>&nums,int i)
{
    int n=nums.size();
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];

    int take=nums[i]+solve(dp,nums,i+2);

    int notTake=0+solve(dp,nums,i+1);
    
    return dp[i]=max(take,notTake);
}
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(dp,nums,0);
        
    }
};