use std::{cmp::{
    max,
    min,
}, usize};

fn check_char(s: &Vec<Vec<char>>, x: usize, y: usize) -> bool {
    let xmax = s[0].len();
    let ymax = s.len();
    for i in (max(1, x) - 1)..(min(x + 1, xmax - 1) + 1){
        for j in (max(1, y) - 1)..(min(y + 1, ymax - 1) + 1) {
            if !s[j][i].is_numeric() && s[j][i] != '.' {
                return true;
            }
        }
    }
    return false;
}

fn check_num(s: &Vec<Vec<char>>, x: usize, y: usize) -> usize {
    let xmax = s[0].len();
    let mut i = x;
    let mut if_good = false;
    let mut num: usize = 0;
    while i < xmax && s[y][i].is_numeric() {
        if check_char(s, i, y)  {
            if_good = true;
        }
        num *= 10;
        num += s[y][i].to_string().parse::<usize>().unwrap();
        i += 1;
    }

    if !if_good {
        num = 0;
    }
    num
}

fn take_numer(s: &Vec<Vec<char>>, x: usize, y: usize) -> (usize, usize, usize){
    let xmax = s[0].len();
    let ymax = s.len();
    let mut a: i32 = x as i32;
    let mut wyn = String::new();
    while s[y][a as usize].is_numeric() && a > 0 {
        a -= 1;
    }
    if a == 0 && s[y][a as usize].is_numeric() {
        a -= 1;
    }
    a += 1;
    let nx: usize = a as usize;
    while s[y][a as usize].is_numeric() && (a as usize) < xmax - 1 {
        wyn += &s[y][a as usize].to_string();
        a += 1;
    }
    if a as usize == xmax - 1 && s[y][a as usize].is_numeric(){
        wyn += &s[y][a as usize].to_string()
    }
    (wyn.parse::<usize>().unwrap(), nx, y)
}

fn check_star(s: &Vec<Vec<char>>, x: usize, y: usize) -> usize {
    let xmax = s[0].len();
    let ymax = s.len();
    let mut u1: (usize, usize, usize) = (0, 0, 0);
    let mut u2: (usize, usize, usize) = (0, 0, 0);
    for i in (max(1, x) - 1)..(min(x + 1, xmax - 1) + 1){
        for j in (max(1, y) - 1)..(min(y + 1, ymax - 1) + 1) {
            if s[j][i].is_numeric() {
                let pom = take_numer(s, i, j);
                if u1.0 == 0 {
                    u1 = pom;
                }
                else if pom != u1 {
                    u2 = pom;
                }
            }
        }
    }
    return u1.0 * u2.0;
}

fn main() {
    let s = include_str!("data.txt");
    let mut schem: Vec<Vec<char>> = vec![];
    for line in s.lines() {
        schem.push(line.chars().collect());
    }
    let mut res:usize = 0;
    let mut res2:usize = 0;

    let xmax = schem[0].len();
    let ymax = schem.len();

    for i in 0..xmax {
        for j in 0..ymax {
            if schem[j][i].is_numeric() && (i == 0 || !schem[j][i - 1].is_numeric()){
                res += check_num(&schem, i, j);
            }
        }
    }
    println!("{}", res);

    for i in 0..xmax {
        for j in 0..ymax {
            if schem[j][i] == '*' {
                res2 += check_star(&schem, i, j);
            }
        }
    }
    println!("{}", res2);

}
