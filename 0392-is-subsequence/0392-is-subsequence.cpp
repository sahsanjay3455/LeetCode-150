class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int n1=s.size();
        int n2=t.size();
        int i=0,j=0;

        while(n1>i && n2>j)
        {
            if(s[i]==t[j])
            {
                i++;
            }
            
            j++;


        }
        if(i==n1)return true;
        
        return false;
        
        
    }
};