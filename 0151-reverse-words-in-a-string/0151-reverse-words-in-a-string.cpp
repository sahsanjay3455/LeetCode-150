class Solution {
public:
    string reverseWords(string s) 
    {
        string word;
        stringstream ss(s);
        vector<string>v;
        while(ss>>word)
        {
           v.push_back(word);
        }
        reverse(begin(v),end(v));
        string result="";
       for(int i=0;i<v.size();i++)
       {
        if(i>0)
        {
            result+=" ";
        }
        result+=v[i];


       }
       return result;
        
    }
};