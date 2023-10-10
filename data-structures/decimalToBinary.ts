import Stack from './stack'

function decimalToBinary(decNumber: number) {
  const remStack = new Stack()
  let number = decNumber
  let rem: number // 余数
  let binaryStr = ''

  while (number > 0) {
    rem = Math.floor(number % 2)
    remStack.push(rem)
    number = Math.floor(number / 2)
  }

  while (!remStack.isEmpty()) {
    binaryStr += remStack.pop()
  }

  return binaryStr
}

console.log(decimalToBinary(233))
console.log(decimalToBinary(10))
console.log(decimalToBinary(1000))

function baseConverter(decNumber: number, base: number) {
  const remStack = new Stack()
  const digits = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ' // A->10, B->11, ...
  let number = decNumber
  let rem: number // 余数
  let baseStr = ''

  if (!(base >= 2 && base <= 36)) {
    return ''
  }

  while (number > 0) {
    rem = Math.floor(number % base)
    remStack.push(rem)
    number = Math.floor(number / base)
  }

  while (!remStack.isEmpty()) {
    baseStr += digits[remStack.pop()]
  }

  return baseStr
}

console.log('-----------------------')
console.log(baseConverter(10, 2))
console.log(baseConverter(10, 8))
console.log(baseConverter(10, 10))
console.log(baseConverter(10, 16))

console.log(baseConverter(100345, 2))
console.log(baseConverter(100345, 8))
console.log(baseConverter(100345, 10))
console.log(baseConverter(100345, 16))
