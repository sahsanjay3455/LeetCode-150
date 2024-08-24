class Solution {
public:
vector<string>result;
int n;

bool isvalid(string str)
{
    if(str[0]=='0')
    {
        return false;
    }
    int num=stoi(str);

    return num<=255;

}
   
   void perform(string s,int idx,int part,string curr)
   {

    if(part==4 && idx==n)
    {
        result.push_back(curr.substr(0,curr.size()-1));
        return ;
    }

    if(idx+1<=n)
    {
        perform(s,idx+1,part+1,curr+s.substr(idx,1)+ ".");
    }

     if((idx+2<=n) && isvalid(s.substr(idx,2)))
    {
        perform(s,idx+2,part+1,curr+s.substr(idx,2)+ ".");

    }

     if((idx+3<=n) && isvalid(s.substr(idx,3)))
    {
        perform(s,idx+3,part+1,curr+s.substr(idx,3)+ ".");

    }

   }
    
    
    vector<string> restoreIpAddresses(string s) 
    {
        result.clear();
    
        n=s.size();
        int part=0;
        string curr="";
        perform(s,0,part,curr);
        return result;

       
        
    }
};