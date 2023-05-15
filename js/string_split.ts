let s = '想陪你一起度过每个夏天'

const keywords = ['你', '每个']

keywords.forEach(word => (s = s.replaceAll(word, '%%')))
const splitList = s.split('%%')
const result = splitList.reduce((acc, item, index) => {
  if (index === splitList.length - 1) {
    acc.push(item)
  } else {
    acc.push(item, keywords[index])
  }

  return acc
}, [])

console.log(result) // [ '想陪', '你', '一起度过', '每个', '夏天' ]
