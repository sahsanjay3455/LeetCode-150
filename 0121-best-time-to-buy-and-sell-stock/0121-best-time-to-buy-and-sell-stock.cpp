class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
       int min_price=INT_MAX;
       int max_profit=0;
       for(int i=0;i<arr.size();i++)
       {
        if(arr[i]<min_price)
        {
            min_price=arr[i];
        }
        else if(arr[i]-min_price>max_profit)
        {
            max_profit=arr[i]-min_price;
        }
       }
       return max_profit;
        
    }
};