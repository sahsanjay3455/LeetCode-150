class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int n=arr.size();
        int min1=arr[0];
        int max_profit=0;
        
        for(int i=1;i<n;i++)
        {
            int cost=arr[i]-min1;
            max_profit=max(max_profit,cost);
            min1=min(min1,arr[i]);
        }
        return max_profit;

        
    }
};