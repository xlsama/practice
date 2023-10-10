// @ts-nocheck
// double-ended queue 双端队列
class Deque {
  constructor() {
    this.items = {}
    this.count = 0
    this.lowestcount = 0
  }

  enqueue(element) {
    this.items[this.count] = element
    this.count++
  }

  dequeue() {
    if (this.isEmpty()) {
      return
    }
    const result = this.items[this.lowestcount]
    this.lowestcount++
    return result
  }

  peek() {
    return this.items[this.lowestcount]
  }

  isEmpty() {
    return this.count - this.lowestcount === 0
  }

  clear() {
    this.items = {}
    this.count = 0
    this.lowestcount = 0
  }

  toString() {
    if (this.isEmpty()) {
      return ''
    }
    let str = this.items[this.lowestcount]
    for (let i = this.lowestcount + 1; i < this.count; i++) {
      str += `,${this.items[i]}`
    }
    return str
  }

  size() {
    return this.count - this.lowestcount
  }
}

const queue = new Deque()
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
