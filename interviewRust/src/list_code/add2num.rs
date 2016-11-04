pub fn run() -> String {
	print_sum(2,3);
    "add2num".to_string()
}

fn print_sum(x: i32, y: i32) {
    println!("sum is: {}", x + y);
}