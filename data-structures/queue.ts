// @ts-nocheck
class Queue {
  constructor() {
    this.items = {}
    this.count = 0
    this.lowestCount = 0
  }

  enqueue(element) {
    this.items[this.count] = element
    this.count++
  }

  dequeue() {
    if (this.isEmpty()) {
      return
    }
    const result = this.items[this.lowestCount]
    this.lowestCount++
    return result
  }

  peek() {
    return this.items[this.lowestCount]
  }

  isEmpty() {
    return this.count - this.lowestCount === 0
  }

  clear() {
    this.items = {}
    this.count = 0
    this.lowestCount = 0
  }

  toString() {
    if (this.isEmpty()) {
      return ''
    }
    let str = this.items[this.lowestCount]
    for (let i = this.lowestCount + 1; i < this.count; i++) {
      str += `,${this.items[i]}`
    }
    return str
  }

  size() {
    return this.count - this.lowestCount
  }
}

const queue = new Queue()
console.log(queue.isEmpty())
queue.enqueue('li')
queue.enqueue('xiao')
queue.enqueue('long')
console.log(queue.size())
console.log(queue.toString())
console.log(queue.peek())
queue.dequeue()
console.log(queue.peek())
console.log(queue.toString())
