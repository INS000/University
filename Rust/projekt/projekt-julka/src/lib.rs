use wasm_bindgen::prelude::*;
use wasm_bindgen::Clamped;
use web_sys::{ImageData, CanvasRenderingContext2d};

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

    fn norm_sqr(&self) -> f64 {
        self.re * self.re + self.im * self.im
    }
}

fn juliet_helper(mut z:Complex, c:Complex, ran:u32) -> u32 {
    let mut i = ran;
    while z.norm_sqr() < 4.0 && i > 1 {
        let tmp = z.re * z.re - z.im * z.im + c.re;
        z.im = 2.0 * z.re * z.im + c.im;
        z.re = tmp;
        i -= 1;
    }
    i
}

#[wasm_bindgen]
pub fn juliet(canvas:CanvasRenderingContext2d, re:f64, im:f64, zoom:f64) -> Result<(), JsValue> {
    let width: u32 = 1024;
    let height: u32 = 1024;

    let c = Complex::new(re, im);
    let imax = 256;
    let mut kolorki:Vec<u8> = Vec::with_capacity(4 * width as usize * height as usize);

    for x in 0..width {
        for y in 0..height {
            let z = Complex::new(((x as f64 * 4.0 / width as f64) - 2.0) / zoom,
                                             ((y as f64 * 4.0 / height as f64) - 2.0) / zoom);

            let i = juliet_helper(z, c, imax);

            let col = (i as f64 / imax as f64 * 255.0) as u8;
            for _i in 0..3 {
                kolorki.push(col);
            }
            kolorki.push(255);
        }
    }
    let tmp = ImageData::new_with_u8_clamped_array_and_sh(Clamped(&kolorki), width, height)?;
    canvas.put_image_data(&tmp, 0.0, 0.0)
}


#[wasm_bindgen]
extern "C" {
    fn alert(s: &str);
}

#[wasm_bindgen]
pub fn greet() {
    alert("Hello, projekt-julka!");
}
