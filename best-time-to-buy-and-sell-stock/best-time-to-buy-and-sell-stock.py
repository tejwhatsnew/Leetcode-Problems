class Solution(object):
    def maxProfit(self, prices):
        mini = prices[0]
        profit = 0

        for i in prices:
            mini = min(i, mini)
            profit = max(i - mini, profit)
        return profit