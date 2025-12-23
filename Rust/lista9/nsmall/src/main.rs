fn first_n_smallest (arr: &[i32], n: usize) -> Vec<i32> { //mozna zgrabniej jedna funkcja z uzyciem sorted a nie sort
    let mut tuples: Vec<(i32, usize)> = arr.iter()
                                           .enumerate()
                                           .map(|(i, &x)| (x, i))
                                           .collect();
    tuples.sort_by(|a, b| a.0.cmp(&b.0));
    tuples = tuples[..n].to_vec();
    tuples.sort_by(|a, b| a.1.cmp(&b.1));
    tuples.iter()
          .map(|(x, _)| *x)
          .collect()
}

#[test]
fn test_basic1() {
    assert_eq!(first_n_smallest(&[1,2,3,4,5],0), []);
}

#[test]
fn test_basic2() {
    assert_eq!(first_n_smallest(&[1,2,3,4,5],3), [1,2,3]);
}

#[test]
fn test_basic3() {
    assert_eq!(first_n_smallest(&[1,2,3,1,2],3), [1,2,1]);
}

#[test]
fn test_basic4() {
    assert_eq!(first_n_smallest(&[1,2,3,-4,0],3), [1,-4,0]);
}

#[test]
fn test_basic5() {
    assert_eq!(first_n_smallest(&[1,2,3,4,5],5), [1,2,3,4,5]);
}

#[test]
fn test_basic6() {
    assert_eq!(first_n_smallest(&[1,2,3,4,2],4), [1,2,3,2]);
}

#[test]
fn test_basic7() {
    assert_eq!(first_n_smallest(&[2,1,2,3,4,2],4), [2,1,2,2]);
}

#[test]
fn test_basic8() {
    assert_eq!(first_n_smallest(&[2,1,2,3,4,2],3), [2,1,2]);
}

#[test]
fn test_basic9() {
    assert_eq!(first_n_smallest(&[2,1,2,3,4,2],2), [2,1]);
}

#[test]
fn test_basic10() {
    assert_eq!(first_n_smallest(&[5,4,3,2,1],3), [3,2,1]);
}

fn main() {
    first_n_smallest(&[2,1,2,3,4,2],3);
}
