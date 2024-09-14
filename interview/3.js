/*
给定一个字符串 s ，找到 它的第一个不重复的字符，并返回这个字符 。如果不存在，则返回 空字符 。
示例 1：
输入: s = "bacde"
输出: a
示例 2:
输入: s = "aabbcdc"
输出: d
示例 3:
输入: s = "aabb"
输出: ''
*/
function main(str) {
  const obj = {}

  for (const s of str) {
    obj[s] = obj[s] ? obj[s] + 1 : 1
  }

  return Object.entries(obj).filter(([key, value]) => value === 1)[0]?.[0] ?? ''
}

// 结果验证
const s1 = 'abcde'
const res1 = main(s1)
console.log(res1)
const s2 = 'aabbcdcdce'
const res2 = main(s2)
console.log(res2)
const s3 = 'aabb'
const res3 = main(s3)
console.log(res3)
