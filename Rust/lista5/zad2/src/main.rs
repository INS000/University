use std::cmp::Reverse;

fn even_numbers(array: &Vec<i32>, number: usize) -> Vec<i32> {
    let mut a = array.iter()
         .copied()
         .filter(|x| *x % 2 == 0)
         .rev()
         .take(number)
         .collect::<Vec<i32>>();
    a.reverse();
    a
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sample_tests1() {
        assert_eq!(even_numbers(&vec!(1, 2, 3, 4, 5, 6, 7, 8, 9), 3), vec!(4, 6, 8));
    }

    #[test]
    fn sample_tests2() {
        assert_eq!(even_numbers(&vec!(-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26), 2), vec!(-8, 26));
    }

    #[test]
    fn sample_tests3() {
        assert_eq!(even_numbers(&vec!(6, -25, 3, 7, 5, 5, 7, -3, 23), 1), vec!(6));
    }

    #[test]
    fn sample_tests4() {
        assert_eq!(even_numbers(&vec!(1, 2, 3, 4, 5, 6, 7, 8, 9), 2), vec!(6, 8));
    }

    #[test]
    fn sample_tests5() {
        assert_eq!(even_numbers(&vec!(1, 2, 3, 4, 5, 6, 7, 8, 9), 1), vec!(8));
    }
}

fn main() {
    println!("Hello, world!");
}
