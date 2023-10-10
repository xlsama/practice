// @ts-nocheck

export default class Stack {
  constructor() {
    this.count = 0
    this.items = {}
  }

  push(element) {
    this.items[this.count] = element
    this.count++
  }

  pop() {
    if (this.isEmpty()) {
      return
    }
    this.count--
    const item = this.items[this.count]
    delete this.items[this.count]
    return item
  }

  peek() {
    if (this.isEmpty()) {
      return
    }
    return this.items[this.count - 1]
  }

  isEmpty() {
    return this.count === 0
  }

  clear() {
    this.count = 0
    this.item = {}
    // while (!this.isEmpty()) {
    //   this.pop()
    // }
  }

  size() {
    return this.count
  }

  toString() {
    if (this.isEmpty()) {
      return ''
    }
    let str = this.items[0]
    for (let i = 1; i < this.count; i++) {
      str += `,${this.items[i]}`
    }
    return str
  }
}

const stack = new Stack()
// console.log(stack.isEmpty())

stack.push(5)
stack.push(8)

// console.log(stack.peek())

stack.push(13)

// console.log(stack.size())
// console.log(stack.isEmpty())

stack.pop()
stack.pop()
// console.log(stack.size())

stack.push(100)
// console.log(stack.toString())
