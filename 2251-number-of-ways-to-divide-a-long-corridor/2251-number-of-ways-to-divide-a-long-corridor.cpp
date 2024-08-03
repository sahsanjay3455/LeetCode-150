class Solution {
public:
   int m=1e9+7;

    int numberOfWays(string corridor) 
    {
        int n=corridor.size();
        vector<int>seat_index;
        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='S')
            seat_index.push_back(i);
        }
        int s_size=seat_index.size();

        if(s_size==0 ||(s_size%2)!=0)
        {
            return 0;
        }
        long long result=1;

        int prev=1;

        for(int i=2;i<s_size;i+=2)
        {
            int length=seat_index[i]-seat_index[prev];

            result=(result*length)%m;
            prev=i+1;
        }
        return result;
    }
};