class Solution {
public:
bool isvowel(char &ch)
{
    ch=tolower(ch);
    return (ch=='a'||ch=='e'|| ch=='i'|| ch=='o' || ch=='u');
}

    bool halvesAreAlike(string str)
{
    int n=str.size();
    int i=0;
    int mid=n/2;
    int j=mid;
    int count_left=0,count_right=0;

    while(i<mid && j<n)
    {
      if (isvowel(str[i])) count_left++;
       if(isvowel(str[j])) count_right++;
       i++;
       j++;
    }
    if(count_left==count_right) return true;

    return false;
}


    
};