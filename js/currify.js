const addTwo = (a, b) => a + b
const addThree = (a, b, c) => a + b + c
const addFore = (a, b, c, d) => a + b + c + d

// 变成柯里化函数
const currify =
  (fn, params = []) =>
  (...args) =>
    params.length + args.length === fn.length
      ? fn(...args, ...params)
      : currify(fn, [...args, ...params])

const newAddTwo = currify(addTwo)
console.log(newAddTwo(1)(2))
const newAddThree = currify(addThree)
console.log(newAddThree(1)(2)(3))
const newAddFore = currify(addFore)
console.log(newAddFore(1)(2, 3)(4))
