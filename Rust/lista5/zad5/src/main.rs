use std::collections::BTreeSet;

fn sum_pairs(ints: &[i8], s: i8) -> Option<(i8, i8)> {
    let mut prev = BTreeSet::new();
    for &num in ints.iter() {
        if prev.contains(&(s - num)) {
            return Some((s - num, num));
        }
        prev.insert(num);
    }
    None
}

#[test]
fn returns_expected1() {
    let l1 = [1, 4, 8, 7, 3, 15];
    assert_eq!(sum_pairs(&l1, 8), Some((1, 7)));
}

#[test]
fn returns_expected2() {
    let l2 = [1, -2, 3, 0, -6, 1];
    assert_eq!(sum_pairs(&l2, -6), Some((0, -6)));
}

#[test]
fn returns_expected3() {
    let l3 = [20, -13, 40];
    assert_eq!(sum_pairs(&l3, -7), None);
}

#[test]
fn returns_expected4() {
    let l4 = [1, 2, 3, 4, 1, 0];
    assert_eq!(sum_pairs(&l4, 2), Some((1, 1)));
}

#[test]
fn returns_expected5() {

    let l5 = [10, 5, 2, 3, 7, 5];
    assert_eq!(sum_pairs(&l5, 10), Some((3, 7)));
}

#[test]
fn returns_expected6() {
    let l6 = [4, -2, 3, 3, 4];
    assert_eq!(sum_pairs(&l6, 8), Some((4, 4)));
}

#[test]
fn returns_expected7() {
    let l7 = [0, 2, 0];
    assert_eq!(sum_pairs(&l7, 0), Some((0, 0)));
}

#[test]
fn returns_expected8() {
    let l8 = [5, 9, 13, -3];
    assert_eq!(sum_pairs(&l8, 10), Some((13, -3)));
}

fn main() {
    println!("Hello, world!");
}
