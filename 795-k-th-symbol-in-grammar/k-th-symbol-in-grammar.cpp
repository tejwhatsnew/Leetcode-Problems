class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        
        // Calculate the size of the nth row.
        int rowSize = 1 << (n - 1);
        
        // Check whether k falls in the first half or the second half of the nth row.
        if (k <= rowSize / 2) {
            // If k is in the first half, it depends on the previous row's k.
            return kthGrammar(n - 1, k);
        } else {
            // If k is in the second half, it depends on the previous row's (k - rowSize / 2).
            return 1 - kthGrammar(n - 1, k - rowSize / 2);
        }
    }
};