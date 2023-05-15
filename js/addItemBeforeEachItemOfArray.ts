const list = [
  [10, 20],
  [20, 30],
]

const addItemBeforeEachItemOfArray = (arr: any[], item: any): any[] => {
  if (!Array.isArray(arr)) {
    throw 'arr必须为数组'
  }
  return arr.reduce((acc, value) => {
    acc.push(item, value)
    return acc
  }, [])
}

console.log(addItemBeforeEachItemOfArray(list, [0, 0])) // [ [ 0, 0 ], [ 10, 20 ], [ 0, 0 ], [ 20, 30 ] ]
console.log(addItemBeforeEachItemOfArray(list, { id: 1 })) // [ { id: 1 }, [ 10, 20 ], { id: 1 }, [ 20, 30 ] ]
