class Solution {
public:
long long countSteps(long long n, long long prefix, long long next) {
    long long steps = 0;
    while (prefix <= n) {
        steps += min(n + 1, next) - prefix;
        prefix *= 10;
        next *= 10;
    }
    return steps;
}


    int findKthNumber(int n, int k) {
        long long curr = 1;
    k -= 1; // since we start from 1
    
    while (k > 0) {
        long long steps = countSteps(n, curr, curr + 1);
        if (steps <= k) {
            // Move to next prefix (sibling)
            curr += 1;
            k -= steps;
        } else {
            // Move to next level (child)
            curr *= 10;
            k -= 1;
        }
    }
    return (int)curr;
    }
};