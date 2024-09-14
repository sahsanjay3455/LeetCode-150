class Solution {
public:
        int reverse(int x) {
        int reversedNum = 0;
        if(x>=0 && x<10)
        {
            return x;
        }

        while (x != 0) {
            int digit = x % 10;

            // Check for overflow:
            if (reversedNum > INT_MAX / 10 || (reversedNum == INT_MAX / 10 && digit > 7)) return 0;
            if (reversedNum < INT_MIN / 10 || (reversedNum == INT_MIN / 10 && digit < -8)) return 0;

            reversedNum = reversedNum * 10 + digit;
            x /= 10;
        }

        return reversedNum;
    }
};