Function.prototype.myCall = function (ctx, ...args) {
  ctx.fn = this
  const result = ctx.fn(...args)
  delete ctx.fn
  return result
}

function greet(name) {
  return `Hello, ${name}! I am ${this.name}.`
}

console.log(greet.myCall({ name: 'Lee' }, 'Wang'))
