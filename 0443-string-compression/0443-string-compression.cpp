class Solution {
public:
    int compress(vector<char>& chars) 
    {
      int n = chars.size();
      if(n==1)
      {
        return 1;
      }
    int index = 0;
    for (int i = 0; i < n ; i++) {
        char curr_ch = chars[i];
        int counter = 1;
        while (i < n - 1 && chars[i + 1] == curr_ch) {
            counter++;
            i++;
        }
        chars[index] = curr_ch;
        index++;
        if (counter > 1) {
            string str = to_string(counter);
            for (char& ch : str) {
                chars[index] = ch;
                index++;
            }
        }
    }
    return index;
        
    }
};