class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n=s.size();
        if(k>1)
        {
            sort(begin(s),end(s));
            return s;
        }

        if(n==1)
        {
            return s;
        }

        string result=s;
        for(int i=1;i<=n-1;i++)
        {
            string temp =s.substr(i)+s.substr(0,i);
            result=min(temp,result);
        }
        return result;
        
    }
};