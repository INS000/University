fn first_right(s: &str) -> i32 {
    for i in s.chars().rev() {
        if i.is_numeric()  {
            return i.to_digit(10).unwrap() as i32;
        }
    }
    -69
}

fn first_left(s: &str) -> i32 {
    for i in s.chars() {
        if i.is_numeric()  {
            return i.to_digit(10).unwrap() as i32;
        }
    }
    -420
}


fn main() {
    let s = include_str!("data.txt");
    let mut res = 0;
    for line in s.lines() {
        res += first_right(line) + first_left(line) * 10;
    }
    println!("{}", res);
    let mut s2 = s.to_string();
    s2 = s2.replace("one", "o1e")
           .replace("two", "t2")
           .replace("three", "t3e")
           .replace("four", "4")
           .replace("five", "5e")
           .replace("six", "6")
           .replace("seven", "7n")
           .replace("eight", "8")
           .replace("nine", "9");
    let mut res2 = 0;
    for line in s2.lines() {
        res2 += first_left(line) * 10 + first_right(line);
    }
    println!("{}", res2);
}
