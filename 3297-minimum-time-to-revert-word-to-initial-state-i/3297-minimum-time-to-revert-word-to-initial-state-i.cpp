class Solution {
public:
bool check(string word,int i,int n)
{
    return (word.substr(0,n-i)==word.substr(i,n-1));
}
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        int count=1;
        int i=k;
        while(i<n)
        {
            if(check(word,i,n))
            {
                break;
            }
            count++;
            i+=k;
        }
        return count;
        
    }
};