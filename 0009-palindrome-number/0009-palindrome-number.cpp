#include<bits/stdc++.h>


class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;
        
        // Single digit numbers are palindromes
        if (x >= 0 && x < 10) return true;
        
        int num = x;
        int sum = 0;
        int rem;
        
        // Reverse the number
        while (num > 0) {
            rem = num % 10;
            
            // Check for overflow before updating sum

            if (sum > (INT_MAX- rem) / 10) {
                return false;
            }
            
            sum = sum * 10 + rem;
            num = num / 10;
        }
        
        // Check if the reversed number is the same as the original number
        return (sum == x);
    }
};