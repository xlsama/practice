// @ts-nocheck

class Stack {
  constructor() {
    this.items = []
  }

  push(...element) {
    this.items.push(...element)
  }

  pop() {
    return this.items.pop()
  }

  peek() {
    return this.items.at(-1)
  }

  isEmpty() {
    return this.items.length === 0
  }

  clear() {
    this.items = []
  }

  size() {
    return this.items.length
  }
}

const stack = new Stack()
console.log(stack.isEmpty())

stack.push(5, 8)

console.log(stack.peek())

stack.push(13)

console.log(stack.size())
console.log(stack.isEmpty())

stack.pop()
stack.pop()
console.log(stack.size())
