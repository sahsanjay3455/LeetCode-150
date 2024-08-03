class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[maxi])
            {
                maxi=i;
            }
        }
        return maxi;
        

    }
        
};