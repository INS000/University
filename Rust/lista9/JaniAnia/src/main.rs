fn pom(n: i32) -> (Vec<i32>, Vec<i32>, i32, i32) {
    let mut john: Vec<i32> = Vec::new();
    let mut ann: Vec<i32> = Vec::new();
    let mut sum_john = 0;
    let mut sum_ann = 1;
    john.push(0);
    ann.push(1);
    for i in 1..n {
        john.push(i - ann[john[(i - 1) as usize] as usize]);
        ann.push(i - john[ann[(i - 1) as usize] as usize]);
        sum_john += john[i as usize];
        sum_ann += ann[i as usize];
    }
    (john, ann, sum_john, sum_ann)
}

fn john(n: i32) -> Vec<i32> {
    pom(n).0
}

fn ann(n: i32) -> Vec<i32> {
    pom(n).1
}

fn sum_john(n: i32) -> i32 {
    pom(n).2
}

fn sum_ann(n: i32) -> i32 {
    pom(n).3
}

#[test]
fn test_john1() {
    assert_eq!(john(11), vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6]);
}

#[test]
fn test_john2() {
    assert_eq!(john(14), vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8]);
}

#[test]
fn test_ann1() {
    assert_eq!(ann(6), vec![1, 1, 2, 2, 3, 3]);
}

#[test]
fn test_ann2() {
    assert_eq!(ann(15), vec![1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9]);
}

#[test]
fn test_sum_john1() {
    assert_eq!(sum_john(75), 1720);
}

#[test]
fn test_sum_john2() {
    assert_eq!(sum_john(78), 1861);
}

#[test]
fn test_sum_ann1() {
    assert_eq!(sum_ann(115), 4070);
}

#[test]
fn test_sum_ann2() {
    assert_eq!(sum_ann(150), 6930);
}

fn main() {
    println!("Hello, world!");
}
