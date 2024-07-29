fn main() {
    let str = String::from("吃饭了吗？");
    println!("{}", str.len());

    for s in str.bytes() {
        println!("{}", s)
    }

    for s in str.chars() {
        println!("{}", s)
    }
}
