# Maksymilian Kochan
# lista 9: zad2
# ruby zad1.rb
# ruby 3.2.2

class Function2D
  def initialize(&block)
    @fun = block
  end

  def value(x, y)
    @fun.call(x, y)
  end

  def volume(a, b, c, d)
    eps = 0.001
    suma = 0
    x = a
    while x < b
      y = c
      while y < d
        suma += eps * value(x, y)
        y += eps
      end
      x += eps
    end
    suma
  end

  def counter_line(a, b, c, d, height)
    punkty = []
    x = a
    eps = 0.001
    while x <= b
      y = c
      while y <= d
        if(value(x, y) - height).abs < eps
          punkty.push([x, y])
        end
        y += eps
      end
      x += eps
    end
    punkty
  end
end
