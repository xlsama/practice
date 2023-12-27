/*
 * @lc app=leetcode.cn id=169 lang=typescript
 *
 * [169] 多数元素
 */

// @lc code=start
function majorityElement(nums: number[]): number {
  let count = 0
  let res = 0
  for (let i = 0; i < nums.length; i++) {
    if (count === 0) {
      res = nums[i]
    }
    count += res === nums[i] ? 1 : -1
  }
  return res
}

// @lc code=end
