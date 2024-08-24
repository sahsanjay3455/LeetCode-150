class Solution {
public:
bool iscapital(char &ch)
{
    return(ch>=65 && ch<=90);
}
    bool detectCapitalUse(string word) 
    {
        int n=word.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            
            if(iscapital(word[i]))
            {
                count++;
            }

        }
        if(count==n || count==0)
        {
            return true;
        }
        if(count==1 && iscapital(word[0]))
        {
            return true;
        }
        
        return false;
    
        
    }
};