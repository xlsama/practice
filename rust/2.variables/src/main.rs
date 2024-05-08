fn main() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("the value of x is: {}", x);

    let a = [1, 2, 3, 4, 5];
    for element in a.iter() {
        println!("the value is {}", element);
    }
}
