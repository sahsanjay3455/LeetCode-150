
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans=start^goal;

        int cnt=0;
        while(ans)
        {
            cnt+=ans&1; //if(ans%2===1)
            ans>>=1; //ans=ans/2

        }
        return cnt;
    }
};