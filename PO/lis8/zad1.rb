# Maksymilian Kochan
# lista 8: zad1
# ruby zad1.rb
# ruby 3.2.2

class Masa
    attr_accessor :kilogramy

    def initialize(weight)
        @kilogramy = weight
    end

    def pound
        2.20462262 * @kilogramy
    end

    def pound= (weight)
        @kilogramy = weight * 0.4535
    end
end

class Dlugosc
    attr_accessor :metry

    def initialize(lenght)
        @metry = lenght
    end

    def feet
        3.2808399 * @metry
    end

    def feet= (lenght)
        @metry = lenght * 0.3048
    end

    def yard
        1.0936132983 * @metry
    end

    def yard= (lenght)
        @metry = lenght * 0.9144
    end
end

class Powierzchnia
    def initialize(m1, m2)
        @a = Dlugosc.new(m1)
        @b = Dlugosc.new(m2)
    end

    def m_sq
        @a.metry * @b.metry
    end

    def hectar
        m_sq.to_f / 10000
    end

    def feet_sq
        @a.feet * @b.feet
    end

    def inch_sq
        feet_sq * 144
    end
end

class Cisnienie
    def initialize(m1, m2, kg)
        @pow = Powierzchnia.new(m1, m2)
        @w = Masa.new(kg)
    end

    def pascal
        @w.kilogramy.to_f * 10 / @pow.m_sq
    end

    def bar
        pascal.to_f / 100000
    end

    def psi
        @w.pound.to_f / @pow.inch_sq
    end
end

s = "hektar"
print s.ljust(15), "cal kwadratowy\n"
for a in 1..5 do
    x = rand(10000)
    y = rand(10000)
    p = Powierzchnia.new(x, y)
    print p.hectar.round(2).to_s.ljust(15), p.inch_sq.round(2), "\n"
end

print "\n"

s = "bary"
print s.ljust(15), "psi\n"
for a in 1..5 do
    x = rand(10) + 1
    y = rand(10) + 1
    z = rand(10000)
    c = Cisnienie.new(x.to_f/10, y.to_f/100, z)
    print c.bar.round(2).to_s.ljust(15), c.psi.round(2), "\n"
end
