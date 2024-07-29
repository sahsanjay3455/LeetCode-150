class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int max_profit=0;
        int min_num=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            min_num=min(prices[i],min_num);
            int profit=prices[i]-min_num;
            max_profit=max(max_profit,profit);

        }
        return max_profit;

        
    }
};