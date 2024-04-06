fn main() {
    let str = "hello world";

    let word = first_word(&str);
    println!("{}", word);
    println!("{}", greet("Lee"));
}

fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.into_iter().enumerate() {
        if item == b' ' {
            return &s[..i];
        }
    }
    &s[..]
}

fn greet(name: &str) -> &str {
    println!("Hello, {}!", name);
    name
}
