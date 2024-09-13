class Solution {
public:
bool isvowel(char ch)
{
    char ch1=tolower(ch);
    
    return (ch1=='a'|| ch1=='e'||ch1=='i'||ch1=='o'||ch1=='u');
}
    string reverseVowels(string s) 
    {
        vector<char>v;

        for(char &ch:s)
        {
            if(isvowel(ch))
            {
                v.push_back(ch);

            }
        }
        reverse(begin(v),end(v));

        int j=0;

        for(int i=0;i<s.size();i++)
        {
            if(isvowel(s[i]))
            {
                s[i]=v[j];
                j++;

            }
        }
        return s;

        
    }
};