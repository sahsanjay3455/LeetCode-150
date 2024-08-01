class Solution {
public:
string building_string(string s)
{
    string temp="";

    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='#')
        {
            temp.push_back(s[i]);
            
        }
       else if(!temp.empty())
       {
        temp.pop_back();
       }
    }
    return temp;

}
    bool backspaceCompare(string s, string t) {
        string first=building_string(s);
        string second=building_string(t);
        
        return first==second;

       
        
    }
};