class Solution {
public:
bool solve(vector<int>&nums, vector<vector<int>>&dp,int i,int sum,int n)
{
    if(sum==0)return true;

    if(i>=n || sum<0)return false;

    if(dp[i][sum]!=-1)return dp[i][sum];

    bool take=solve(nums,dp,i+1,sum-nums[i],n);

    bool notTake=solve(nums,dp,i+1,sum,n);

    return dp[i][sum]=(take || notTake);

}
    bool canPartition(vector<int>& nums)
    {
        int n=nums.size();
        int sum= accumulate(begin(nums),end(nums),0);

        if(sum%2!=0)return false;
        int subset_sum=sum/2;

        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(nums,dp,0,subset_sum,n);
    }
};