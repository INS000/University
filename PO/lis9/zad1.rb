# Maksymilian Kochan
# lista 9: zad1
# ruby zad1.rb
# ruby 3.2.2

class Function
  def initialize(&block)
    @fun = block
  end

  def value(x)
    @fun.call(x)
  end

  def zero(a, b, e)
    left = a
    right = b
    while (right - left).abs > e
      mid = (left + right) / 2
      if value(mid) == 0
        return mid
      elsif value(left) * value(mid) < 0
        right = mid
      else
        left = mid
      end
    end
    nil
  end

  def field(a, b)
    dl = (b - a) / 10000.0
    suma = 0
    for i in 0..9999
      x = a + i * dl
      suma += value(x) * dl
    end
    suma
  end

  def deriv(x)
    h = 0.000001
    (value(x + h) - value(x)) / h
  end
end
