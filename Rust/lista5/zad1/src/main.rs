fn count_odd_pentafib(n: u16) -> u16 {
    let mut a = 0;

    if n % 6 == 1 {
        a = 1;
    }

    if n == 0 {
        return 0;
    }

    if n <= 6 {
        return 1;
    }

    (n - 1) / 6 * 2 + 1 - a
}

#[cfg(test)]
mod tests {
    use super::count_odd_pentafib;

    #[test]
    fn basic_tests1() {
        assert_eq!(count_odd_pentafib(5), 1);
    }

    #[test]
    fn basic_tests2() {
        assert_eq!(count_odd_pentafib(10), 3);
    }

    #[test]
    fn basic_tests3() {
        assert_eq!(count_odd_pentafib(15), 5);
    }

    #[test]
    fn basic_tests4() {
        assert_eq!(count_odd_pentafib(45), 15);
    }

    #[test]
    fn basic_tests5() {
        assert_eq!(count_odd_pentafib(68), 23);
    }


    #[test]
    fn edge_cases1() {
        assert_eq!(count_odd_pentafib(0), 0);
    }

    #[test]
    fn edge_cases2() {
        assert_eq!(count_odd_pentafib(2), 1);
    }

    #[test]
    fn edge_cases3() {
        assert_eq!(count_odd_pentafib(1), 1);
    }
}

fn main() {
    println!("Hello, world!");
}
