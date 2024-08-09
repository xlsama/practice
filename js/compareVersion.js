/**
 * 比较两个版本号
 * @param {string} version1 第一个版本号
 * @param {string} version2 第二个版本号
 * @return {number} 如果version1 > version2,返回1;如果version1 < version2,返回-1;如果相等,返回0
 */
function compareVersions(version1, version2) {
  const v1 = version1.split('.').map(Number)
  const v2 = version2.split('.').map(Number)

  for (let i = 0; i < Math.max(v1.length, v2.length); i++) {
    const num1 = v1[i] || 0
    const num2 = v2[i] || 0

    if (num1 < num2) return -1
    if (num1 > num2) return 1
  }

  return 0
}

// 测试用例
console.log(compareVersions('1.0', '1.0.0')) // 应该输出 0
console.log(compareVersions('0.1', '1.1')) // 应该输出 -1
console.log(compareVersions('1.0.1', '1')) // 应该输出 1
console.log(compareVersions('7.5.2.4', '7.5.3')) // 应该输出 -1
