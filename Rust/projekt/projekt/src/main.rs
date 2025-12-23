struct Image {
    width : usize,
    height : usize,
    data : Vec<(u8, u8, u8)>
}

use std::fs::File;
use std::io::Write;
use std::path::Path;
use std::io::BufWriter;

impl Image {
    fn new(w : usize, h : usize) -> Image {
        Image { width: (w),
                height: (h),
                data: (vec![(0u8, 0u8, 0u8); w * h])
        }
    }

    fn set_color(&mut self, x: usize, y: usize, r: u8, g: u8, b: u8){
        assert!(y < self.height);
        assert!(x < self.width);
        let color = (r, g, b);
        self.data[y * self.width + x] = color;
    }

    fn im_to_ppm(self, path : &str) {
        let mut file = BufWriter::new(File::create(Path::new(path)).expect("unable to create file"));
        writeln!(&mut file, "P3").expect("unable to write P3");
        writeln!(&mut file, "{} {}", self.width, self.height).expect("unable to write height and width");
        writeln!(&mut file, "255").expect("unable to write max size");
        let mut i: usize = 1;
        for (r, g, b) in self.data{
            write!(&mut file, "{} {} {} ", r, g, b).expect("unable to write color");
            if i % self.width == 0 {
                write!(&mut file, "\n").expect("unable to write enter");
            }
            i += 1;
        }
    }
}


#[derive(Debug, Clone, Copy)]
struct Complex {
    re : f64,
    im : f64
}

impl Complex {
    fn new (re: f64, im: f64) -> Complex {
        Complex { re: (re),
                  im: (im)
        }
    }

    fn print(&self) {
        println!("imaginary: {}, real: {}", self.im, self.re);
    }

    fn con(&self) -> Complex {
        Complex { re: (self.re),
                  im: (-self.im) }
    }

    fn norm_sqr(&self) -> f64 {
        self.re * self.re + self.im * self.im
    }
}

use std::{ops};

impl ops::Add<Complex> for Complex {
    type Output = Complex;

    fn add(self, rhs: Complex) -> Self::Output {
        Complex {
            re: self.re + rhs.re,
            im: self.im + rhs.im
        }
    }
}

impl ops::AddAssign<Complex> for Complex {
    fn add_assign(&mut self, rhs: Complex) {
        *self = *self + rhs
    }
}

impl ops::Sub<Complex> for Complex {
    type Output = Complex;

    fn sub(self, rhs: Complex) -> Self::Output {
        Complex {
            re: self.re - rhs.re,
            im: self.im - rhs.im
        }
    }
}

impl ops::SubAssign<Complex> for Complex {
    fn sub_assign(&mut self, rhs: Complex) {
        *self = *self - rhs
    }
}

impl ops::Mul<Complex> for Complex {
    type Output = Complex;

    fn mul(self, rhs: Complex) -> Self::Output {
        Complex {
            re: self.re * rhs.re - self.im * rhs.im,
            im: self.re * rhs.im + self.im * rhs.re
        }
    }
}

impl ops::MulAssign<Complex> for Complex {
    fn mul_assign(&mut self, rhs: Complex) {
        *self = *self * rhs
    }
}

impl ops::Div<Complex> for Complex {
    type Output = Complex;

    fn div(self, rhs: Complex) -> Self::Output {
        let sq_con: f64 = rhs.im * rhs.im + rhs.re * rhs.re;
        Complex {
            re: (self.re * rhs.re + self.im * rhs.im) / sq_con,
            im: (self.re * rhs.im + self.im * rhs.re) / sq_con
        }
    }
}

impl ops::DivAssign<Complex> for Complex {
    fn div_assign(&mut self, rhs: Complex) {
        *self = *self / rhs
    }
}

const limit : usize = 1000;

fn if_Mandragora(c: Complex) -> usize {
    let mut z = Complex::new(0 as f64, 0 as f64);
    let mut counter: usize = 0;
    while z.norm_sqr() <= 4 as f64 && counter < limit {
        z *= z;
        z += c;
        counter += 1;
    }
    return counter;
}

fn gen_Mandelbrot(w: usize, h: usize, lb: Complex, rt: Complex, p: &str) {
    let mut im = Image::new(w, h);
    let rejump = (rt.re - lb.re) / w as f64;
    let imjump = (rt.im - lb.im) / h as f64;
    let mut mendel = lb;
    // let mut file2 = BufWriter::new(File::create(Path::new("./test.txt")).expect("unable to create file"));
    for y in 0..h {
        for x in 0..w {
            mendel.re += rejump;
            let color = 255 - (if_Mandragora(mendel) * 255 / limit);
            // let color = if_Mandragora(mendel);
            im.set_color(x, y, color as u8, 0, color as u8);
            // nieudana próba kolorkow
            // if color == 1000 {
            //     im.set_color(x, y, 0, 0, color as u8);
            // }else {
            //     let c = color as f64;
            //     let r = (255.0f64 * (((10.0f64 * c - 0.3).sin()) / 2 as f64 + 0.5)) as u8;
            //     // writeln!(&mut file2, "{}", color).expect("wrong");
            //     let g = (255.0f64 * ((10.0f64 * c - 4.2).sin() / 2 as f64 + 0.5)) as u8;
            //     let b = (255.0f64 * ((10.0f64 * c - 2.69).sin() / 2 as f64 + 0.5)) as u8;
            //     // println!("{}", color);
            //     im.set_color(x, y, r, r, r);
            // }

        }
        mendel.re = lb.re;
        mendel.im += imjump;
    }
    im.im_to_ppm(p);
}


fn main() {
    let mut a = Complex::new(-2 as f64, -1.5 as f64);
    let mut b = Complex::new(1 as f64, 1.5 as f64);
    gen_Mandelbrot(1200, 800, a, b, "./ob1.ppm");

    a = Complex::new(-0.78 as f64, -0.1 as f64);
    b = Complex::new(-0.74 as f64, -0.06 as f64);
    gen_Mandelbrot(800, 600, a, b, "./ob2.ppm");

    a = Complex::new(-0.76 as f64, -0.08 as f64);
    b = Complex::new(-0.762 as f64, -0.088 as f64);
    gen_Mandelbrot(1000, 620, a, b, "./ob3.ppm");

    a = Complex::new(-0.348537 as f64, -0.60659 as f64);
    b = Complex::new(-0.348314 as f64, -0.60648 as f64);
    gen_Mandelbrot(1400, 700, a, b, "./ob4.ppm");

}
