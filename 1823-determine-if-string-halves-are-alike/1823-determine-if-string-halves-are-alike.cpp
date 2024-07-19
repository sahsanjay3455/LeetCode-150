class Solution {
public:
    bool halvesAreAlike(string str) {

        unordered_set<char>st={'a','e','i','o','u','A','E','I','O','U'};
    int n=str.length();
    int mid=n/2;
    int i=0,j=mid;
    int countL=0,countR=0;
    while(i<mid && j<n)
    {
        if(st.find(str[i])!=st.end())countL++;
        if(st.find(str[j])!=st.end())countR++;
        i++;
        j++;

    }
    if(countL==countR)
    {
        return true;
    }
    else
    {
        return false;
    }
        
    }
};