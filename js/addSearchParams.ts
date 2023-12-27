const addSearchParams = (
  url: string,
  params: Record<string, string | number | undefined | null>,
): string => {
  let [str, search] = url.split('?')
  let searchParams: URLSearchParams
  let hasQuestionMark = false

  const formatParams = Object.entries(params).reduce(
    (obj: Record<string, string>, [key, value]) => {
      if (!value) {
        return obj
      }

      if (typeof value === 'number') {
        obj[key] = value.toString()
        return obj
      }

      obj[key] = value
      return obj
    },
    {},
  )

  if (search) {
    searchParams = new URLSearchParams(search)
    new URLSearchParams(formatParams).forEach((value, key) =>
      searchParams.append(key, value),
    )
  } else {
    searchParams = new URLSearchParams(formatParams)
  }

  searchParams.forEach((value, key) => {
    const symbol = hasQuestionMark ? '&' : '?'
    str += `${symbol}${key}=${value}`
    hasQuestionMark = true
  })

  return str
}

console.log(
  addSearchParams('baidu.com?id=1', {
    name: 'lee',
    age: 20,
    foo: undefined,
    bar: null,
  }),
)
console.log(addSearchParams('baidu.com', { name: 'lee', age: 20 }))
