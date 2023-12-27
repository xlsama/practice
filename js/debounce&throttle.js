// 防抖
function debounce(fn, delay) {
  let timer = null
  let _this = this

  return function (...args) {
    clearTimeout(timer)
    timer = setTimeout(() => {
      fn.apply(_this, args)
    }, delay)
  }
}

// 节流
function throttle(fn, threshold) {
  let _this = this
  let last

  return function (...args) {
    if (!last || Date.now() - last >= threshold) {
      fn.apply(_this, args)
      last = Date.now()
    }
  }
}
