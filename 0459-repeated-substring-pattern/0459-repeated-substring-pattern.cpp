class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=n/2;l>=1;l--)
        {
            if(n%l==0)
            {
                int times=n/l;
                string temp=s.substr(0,l);
                string newstr="";
                while(times--)
                {
                    newstr +=temp;
                }
                if(newstr==s)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};