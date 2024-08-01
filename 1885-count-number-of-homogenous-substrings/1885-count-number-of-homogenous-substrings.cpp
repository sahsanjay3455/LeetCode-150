class Solution {
public:
int MOD=1e9+7;

    int countHomogenous(string s) 
    {
        int result=0;
        int length=0;
        for(int i=0;i<s.size();i++)
        {
            if(i>0 && s[i]==s[i-1])
            {
                length++;
            }
            else
            {
                length=1;
            }
            result=(result+length)%MOD;
        }
        return result;
        

        
    }
};