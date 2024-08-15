class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        int n = s.length();
    unordered_set<char>st(begin(s),end(s));
    int result=0;
    for(auto it:st)
    {
        int start=-1;
        int end=-1;

        for(int i=0;i<n;i++)
        {
            if(it==s[i])
            {
                if(start==-1)
                {
                    start=i;
                }
                end=i;
            }

        }

       unordered_set<char>ch;

       for(int i=start+1;i<end;i++)
       {
        ch.insert(s[i]);
       }
       int size_set=ch.size();

       result+=size_set;
       
    }
    return result;
        
    }
};