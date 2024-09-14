/*
	json 为函数的输入，json2 为函数的输出，需要输出一个新的对象
	在每一个有 name 的层级中，增加一个字段 nickname，为两个 name 的叠加
	child 要么没有，要么就一定是个对象
*/
const json = {
  name: 'a',
  child: {
    name: 'b',
    child: {
      name: 'c',
      child: {
        name: 'd',
        child: {
          name: 'e',
        },
      },
    },
  },
}

const json2 = {
  name: 'a',
  nickname: 'aa',
  child: {
    name: 'b',
    nickname: 'bb',
    child: {
      name: 'c',
      nickname: 'cc',
      child: {
        name: 'd',
        nickname: 'dd',
        child: {
          name: 'e',
          nickname: 'ee',
        },
      },
    },
  },
}

function main(obj) {
  obj.nickname = obj.name + obj.name
  if (obj.child) {
    obj.child = main(obj.child)
  }
  return obj
}

const res = main(json)

console.log(JSON.stringify(res, null, 2))
