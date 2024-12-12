class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int>st(begin(nums),end(nums));
        int result=0;

        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int cnt=0;
                int x=it;
                while(st.find(x)!=st.end())
                {
                    x++;
                    cnt++;
                }
                result=max(result,cnt);
            }
        }
        return result;

        
    }
};