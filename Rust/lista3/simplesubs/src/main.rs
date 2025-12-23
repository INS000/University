struct Cipher {
    mapa1: String,
    mapa2: String,
  }

  impl Cipher {
    fn new(map1: &str, map2: &str) -> Cipher {
      Cipher { mapa1: (String::from(map1)), mapa2: String::from(map2) }
    }

    fn encode(&self, string: &str) -> String {
      string.chars().map(|x| self.mapa2.chars().nth(self.mapa1.find(x).unwrap()).unwrap()).collect()
    }

    fn decode(&self, string: &str) -> String {
      string.chars().map(|x| self.mapa1.chars().nth(self.mapa2.find(x).unwrap()).unwrap()).collect()
    }
  }


  #[test]
fn example1() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.encode("abc"), "eta");
}

#[test]
fn example2() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.encode("xyz"), "qxz");
}


#[test]
fn example3() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.decode("eirfg"), "aeiou");
}


#[test]
fn example4() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.decode("erlang"), "aikcfu");
}


#[test]
fn example5() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.encode("yeti"), "xibr");
}

#[test]
fn example6() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.decode("xibr"), "yeti");
}

#[test]
fn example7() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.encode("ala"), "eue");
}

#[test]
fn example8() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.decode("eue"), "ala");
}

#[test]
fn example9() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.encode("lol"), "ufu");
}


#[test]
fn example10() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);

  assert_eq!(cipher.decode("ufu"), "lol");
}


fn main() {
    println!("Hello, world!");
}
