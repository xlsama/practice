fn main() {
    let number_list = vec![10, 20, 5, 50, 100, 23, 200];
    let mut target = number_list[0];

    for n in number_list {
        if n > target {
            target = n;
        }
    }

    println!("{}", target);
}
