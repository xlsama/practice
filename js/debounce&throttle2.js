// 防抖
function debounce(fn, delay) {
  const _this = this
  let timer

  return function (...args) {
    clearInterval(timer)
    timer = setTimeout(() => {
      fn.apply(_this, args)
    }, delay)
  }
}

function print() {
  console.log('hi')
}

const debounce_fn = debounce(print, 2000)

// debounce_fn()
// debounce_fn()

// 节流
function throttle(fn, threshold) {
  const _this = this
  let last

  return function (...args) {
    if (!last || Date.now() - threshold >= last) {
      fn.apply(_this, args)
      last = Date.now()
    }
  }
}

const throttle_fn = throttle(print, 2000)

throttle_fn()
setTimeout(() => {
  throttle_fn()
}, 1000)
setTimeout(() => {
  throttle_fn()
}, 2000)
