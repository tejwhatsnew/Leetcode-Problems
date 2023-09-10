class Solution {
private:
    const int MOD = 1000000007;
public:
    int countOrders(int n) {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * (2 * i - 1) * i) % MOD;
        }
        return result;
    }
};