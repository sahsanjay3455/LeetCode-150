class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n=arr.size();
        int arr_sum=0,index_sum=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            arr_sum+=arr[i];
            index_sum+=i;
            if(arr_sum==index_sum)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};