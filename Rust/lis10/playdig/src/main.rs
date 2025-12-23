fn dig_pow(n: i64, mut p: i32) -> i64 {
    let a = n.to_string()
             .chars()
             .map(|x| x.to_digit(10).unwrap())
             .collect::<Vec<u32>>();
    let mut sum = 0;
    for b in a {
        sum += i64::pow(b as i64, p as u32);
        p += 1;
    }
    if sum % n == 0 {
        return sum / n;
    }
    return -1;
}

#[cfg(test)]
    mod tests {
    use super::*;

    fn dotest(n: i64, p: i32, exp: i64) -> () {
        println!(" n: {:?};", n);
        println!("p: {:?};", p);
        let ans = dig_pow(n, p);
        println!(" actual:\n{:?};", ans);
        println!("expect:\n{:?};", exp);
        println!(" {};", ans == exp);
        assert_eq!(ans, exp);
        println!("{};", "-");
    }

    #[test]
    fn basic_tests1() {
        dotest(89, 1, 1);
    }

    #[test]
    fn basic_tests2() {
        dotest(92, 1, -1);
    }

    #[test]
    fn basic_tests3() {
        dotest(46288, 3, 51);
    }

    #[test]
    fn basic_tests4() {
        dotest(75, 2, -1);
    }

    #[test]
    fn basic_tests5() {
        dotest(7388, 2, 5);
    }
}


fn main() {
    for i in 1..100000{
        if dig_pow(i, 2) > 0{
            println!("{}", i)
        }
    }
}
