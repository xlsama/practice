Function.prototype.myBind = function (asThis, ...args) {
  const fn = this
  function resultFn(...args2) {
    // 判断是否是new调用
    return fn.call(this instanceof resultFn ? this : asThis, ...args, ...args2)
  }
  resultFn.prototype = fn.prototype
  return resultFn
}

const foo = function (p1, p2) {
  this.p1 = p1
  this.p2 = p2
}

foo.prototype.sayHi = function () {}
const bindFoo = foo.myBind(undefined, 'a', 'b')
const obj = new bindFoo('x', 'y')

console.log(obj)
console.assert(obj.p1 === 'a', 'a')
console.assert(obj.p2 === 'b', 'b')
console.assert(obj.__proto__ === foo.prototype)
console.assert(typeof obj.sayHi === 'function')
