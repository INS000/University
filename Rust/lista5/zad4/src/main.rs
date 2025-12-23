fn expanded_form(n: u64) -> String {
    let mut digits = n.to_string();
    let mut size = digits.len();
    let mut dig = digits.chars();
    let mut res = String::new();
    res.push(dig.next()
                    .unwrap());
    res += &"0".repeat(size - 1);
    size -= 1;
    for a in dig {
        if a != '0' {
            res += " + ";
            res.push(a);
            res += &"0".repeat(size - 1);
        }
        size -= 1;
    }
    res
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn examples1() {
        assert_eq!(expanded_form(12), "10 + 2");
    }

    #[test]
    fn examples2() {
        assert_eq!(expanded_form(42), "40 + 2");
    }

    #[test]
    fn examples3() {
        assert_eq!(expanded_form(70304), "70000 + 300 + 4");
    }

    #[test]
    fn examples4() {
        assert_eq!(expanded_form(72), "70 + 2");
    }

    #[test]
    fn examples5() {
        assert_eq!(expanded_form(420), "400 + 20");
    }
}

fn main() {
    println!("{}", expanded_form(12));
}
