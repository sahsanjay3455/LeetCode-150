class Solution {
public:
int countPrimes(int n) {
    if (n <= 2) return 0; // No prime numbers less than 2
    
    vector<bool> isPrime(n, true); // Boolean array to track prime status
    
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
    
    // Sieve of Eratosthenes
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    
    // Count primes less than n
    int primeCount = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) primeCount++;
    }
    
    return primeCount;
}

};