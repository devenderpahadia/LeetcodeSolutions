class Solution {
public:
    int findNthDigit(int n) {
        long base = 1, mult = 1; 
        for (; n > 9*base*mult; n -= 9*base*mult, base *= 10, ++mult);
        int q = (n-1)/mult, r = (n-1) % mult; 
        return to_string(q+base)[r] - '0'; 
    }
};