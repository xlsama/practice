Function.prototype.myApply = function (ctx, argsArray) {
  ctx.fn = this
  const result = ctx.fn(...argsArray)
  delete ctx.fn
  return result
}

function greet(name) {
  return `Hello, ${name}! I am ${this.name}.`
}

console.log(greet.myApply({ name: 'Lee' }, ['Wang']))
