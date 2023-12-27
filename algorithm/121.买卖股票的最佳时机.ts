/*
 * @lc app=leetcode.cn id=121 lang=typescript
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
function maxProfit(prices: number[]): number {
  let min = prices[0]
  let maxProfit = 0
  for (let i = 1; i < prices.length; i++) {
    if (prices[i] < min) {
      min = prices[i]
    }
    maxProfit = Math.max(maxProfit, prices[i] - min)
  }

  return maxProfit
}
// @lc code=end
