class Solution {
public:
void permuteHelper(vector<int>&nums,int indx,vector<vector<int>>&result)
{
    if(indx==nums.size())
    {
         result.push_back(nums);
         return ;
    }
    for(int i=indx;i<nums.size();i++)
    {
        swap(nums[indx],nums[i]);
        permuteHelper(nums,indx+1,result);
        swap(nums[indx],nums[i]);
    }
}
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>result;
       permuteHelper(nums,0,result);
       return result;

    }
 
};