class Solution {
public:
    int minSteps(string s, string t) {
        int mp_s[26]={0};
        int mp_t[26]={0};
        for(int i=0;i<s.size();i++)
        {
            mp_s[s[i]-'a']++;
            mp_t[t[i]-'a']++;

        }
        int result=0;
        for(int i=0;i<26;i++)
        {
            if(mp_s[i]>mp_t[i])
            {
                result+=(mp_s[i]-mp_t[i]);
            }
        }
        return result;
        
    }
};