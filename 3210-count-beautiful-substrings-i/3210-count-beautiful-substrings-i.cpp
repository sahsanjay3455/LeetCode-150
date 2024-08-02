class Solution {
public:
bool isvowel(char &ch)
{
    return(ch=='a'||ch=='i'||ch=='o'||ch=='u'||ch=='e');
}
    int beautifulSubstrings(string s, int k) 
    {
        int n=s.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            int vowel=0;
            int consonant=0;
            
            for(int j=i;j<n;j++)
            {
                if(isvowel(s[j]))
                {
                    vowel++;
                }
                else
                {
                    consonant++;

                } 
                if(vowel==consonant && (vowel*consonant)% k ==0 )
                {
                    result++;
                }
             
            }
           
        } 
        return result;       
    }
};