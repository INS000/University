fn main() {
    let mut s = include_str!("data.txt").lines();
    let a = s.next().unwrap().to_string();
    let b = s.next().unwrap().to_string();
    let mut time = a.split_whitespace().collect::<Vec<&str>>();
    let mut  dis = b.split_whitespace().collect::<Vec<&str>>();
    time.remove(0);
    dis.remove(0);

    let n = time.len();

    let times = time.iter().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<usize>>();
    let dist = dis.iter().map(|x| x.parse::<usize>().unwrap()).collect::<Vec<usize>>();

    // let times = vec![40, 82, 84, 92];
    // let dist = vec![233, 1011, 1110, 1487];

    let mut odp = 1;
    for i in 0..n {
        let mut pom = 0;
        for j in 0..=times[i] {
            if j * (times[i] - j) > dist[i] {
                pom += 1;
            }
        }
        odp *= pom;
    }
    println!("{}", odp);

    let mut  time2 = String::new();
    let mut dist2 = String::new();
    for a in time {
        time2 += a;
    }

    for a in dis {
        dist2 += a;
    }
    let t = time2.parse::<usize>().unwrap();
    let d = dist2.parse::<usize>().unwrap();
    let mut odp2 = 0;
    for j in 0..=t {
        if j * (t - j) > d {
            odp2 += 1;
        }
    }
    println!("{}", odp2);

}
