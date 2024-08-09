/**
 * 高级字符串模板替换
 * @param {string} template 模板字符串
 * @param {Object} data 替换数据对象
 * @return {string} 替换后的字符串
 */
function advancedTemplateReplace(template, data) {
  let result = ''

  let record = false
  let key = ''

  // a{bw}c{d}
  for (let i = 0; i < template.length; i++) {
    const s = template[i]

    if (s === '{') {
      record = true
      continue
    }

    if (s === '}') {
      record = false

      console.log({ key })
      result += get(data, key) ?? `{${key}}`
      key = ''

      continue
    }

    if (record) {
      key += s
    } else {
      result += s
    }
  }

  return result
}

function get(obj, keyLike) {
  return keyLike.split('.').reduce((acc, key) => acc?.[key], obj)
}

// 测试用例
console.log(advancedTemplateReplace('a{b}c', { b: '11' })) // 应该输出 "a11c"
console.log(advancedTemplateReplace('a{bw}c{d}', { bw: '1', d: '2' })) // 应该输出 "a1c2"
console.log(advancedTemplateReplace('Hello, {user.name}!', { user: { name: 'Alice' } })) // 应该输出 "Hello, Alice!"
console.log(advancedTemplateReplace('{a.b.c}', { a: { b: { c: 'nested' } } })) // 应该输出 "nested"
console.log(advancedTemplateReplace('{a} {b} {c}', { a: '1', c: '3' })) // 应该输出 "1 {b} 3"
