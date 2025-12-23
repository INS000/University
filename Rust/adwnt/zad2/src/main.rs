

fn main() {
    let s = include_str!("data.txt");
    let s1 = s.replace(",", "")
                      .replace(";", "");
    let mut it = 1;
    let mut res = 0;

    for line in s1.lines() {
        let mut red = 0;
        let mut green = 0;
        let mut blue = 0;
        let mut check = true;
        let x: Vec<&str> = line.split(' ').collect();
        for i in (3 .. x.len()).step_by(2) {
            match x[i] {
                "red"   => red = x[i-1].parse::<i32>()
                                        .unwrap(),
                "green" => green = x[i-1].parse::<i32>()
                                          .unwrap(),
                "blue"  => blue = x[i-1].parse::<i32>()
                                         .unwrap(),
                _       => (),
            }
            if red > 12 || green > 13 || blue > 14 {
                check = false;
            }
        }
        if(check) {
            res += it;
        }
        it += 1;
    }
    println!("{}", res);

    let mut res2 = 0;

    use std::cmp::max;

    for line in s1.lines() {
        let mut red = 0;
        let mut green = 0;
        let mut blue = 0;
        let x: Vec<&str> = line.split(' ').collect();
        for i in (3 .. x.len()).step_by(2) {
            match x[i] {
                "red"   => red = max( x[i-1].parse::<i32>()
                                                .unwrap(),
                                                red),
                "green" => green = max( x[i-1].parse::<i32>()
                                                   .unwrap(),
                                                green),
                "blue"  => blue = max( x[i-1].parse::<i32>()
                                                 .unwrap(),
                                                blue),
                _       => (),
            }
        }
        res2 += red * green * blue;
    }

    println!("{}", res2);
}
