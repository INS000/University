use std::cmp;

fn last_digit(str1: &str, str2: &str) -> i32 {
    let mut rests = 1;

    if str2 == "0"{
      return rests;
    }

    let mut mods: [i32; 4] = [0; 4];
    let pom = cmp::min(str2.len(), 2);
    let &num = &str2[str2.len()-pom..].parse::<i32>().unwrap();
    let &dig = &str1[str1.len()-1..].parse::<i32>().unwrap();


    for i in 0..4{
      rests = (rests * dig) % 10;
      mods[i] = rests;
    }
    let mut pom2: i32 = (num - 1) % 4;
    if pom2 == -1{
      pom2 = 3;
    }
    return mods[pom2 as usize]
  }

#[test]
fn returns_expected1() {
  assert_eq!(last_digit("4", "1"), 4);
}

#[test]
fn returns_expected2() {
  assert_eq!(last_digit("4", "2"), 6);
}

#[test]
fn returns_expected3() {
  assert_eq!(last_digit("9", "7"), 9);
}

#[test]
fn returns_expected4() {
  assert_eq!(last_digit("10","10000000000"), 0);
}

#[test]
fn returns_expected5() {
  assert_eq!(last_digit("1606938044258990275541962092341162602522202993782792835301376","2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"), 6);
}

#[test]
fn returns_expected6() {
  assert_eq!(last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"), 7);
}

#[test]
fn returns_expected7() {
  assert_eq!(last_digit("9", "0"), 1);
}

#[test]
fn returns_expected8() {
  assert_eq!(last_digit("9", "7"), 9);
}

#[test]
fn returns_expected9() {
  assert_eq!(last_digit("9", "2"), 1);
}

#[test]
fn returns_expected10() {
  assert_eq!(last_digit("2", "3"), 8);
}



fn main() {
    println!("{}", -1 % 4);
}
