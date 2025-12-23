use std::cmp::min;

fn main() {
    let s = include_str!("data.txt");
    //zad1
    let mut o = 0;
    for l in s.lines() {
        let (le, r) = l.split_once("|").unwrap();
        let tmp1 = le.to_string();
        let tmp2 = r.to_string();
        let mut fir = tmp1.split_whitespace().collect::<Vec<&str>>();
        let snd = tmp2.split_whitespace().collect::<Vec<&str>>();

        fir = fir[2..].to_vec();

        let mut hist: Vec<bool> = vec![false; 100];
        for a in fir {
            hist[a.parse::<usize>().unwrap()] = true;
        }

        let mut odp = 0;

        for b in snd {
            if hist[b.parse::<usize>().unwrap()] == true {
                odp += 1;
            }
        }
        if odp > 0{
            o += 2i32.pow(odp - 1);
        }
    }
    println!("{}", o);

    //zad2
    let mut o2 = 0;
    let mut scratch = vec![1; 205];

    let mut i: usize = 1;

    for l in s.lines() {
        let (le, r) = l.split_once("|").unwrap();
        let tmp1 = le.to_string();
        let tmp2 = r.to_string();
        let mut fir = tmp1.split_whitespace().collect::<Vec<&str>>();
        let snd = tmp2.split_whitespace().collect::<Vec<&str>>();

        fir = fir[2..].to_vec();

        let mut hist: Vec<bool> = vec![false; 100];
        for a in fir {
            hist[a.parse::<usize>().unwrap()] = true;
        }

        let mut odp: usize = 0;

        for b in snd {
            if hist[b.parse::<usize>().unwrap()] == true {
                odp += 1;
            }
        }

        for a in i + 1 ..= min(i + odp, 204) {
            scratch[a] += scratch[i];
        }
        i += 1;
    }

    for a in scratch {
        o2 += a;
    }
    println!("{}", o2 - 1);
}
