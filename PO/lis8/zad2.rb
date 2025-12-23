# Maksymilian Kochan
# lista 8: zad2
# ruby zad2.rb
# ruby 3.2.2

class Dlugosc
  attr_accessor :kilometry

  def initialize(lenght)
      @kilometry = lenght
  end

  def milemorskie
    0.53996 * @kilometry
  end

  def milemorskie= (lenght)
      @kilometry = lenght * 1.852
  end
end

class Czas
  attr_accessor :sek

  def initialize(time)
    @sek = time
  end

  def hour
    @sek.to_f / 3600
  end

  def hour=(time)
    @sek = time * 3600
  end
end

class Predkosc
  def initialize(km, sek)
    @time = Czas.new(sek)
    @route = Dlugosc.new(km)
  end

  def kmh
    @route.kilometry / @time.hour.to_f
  end

  def kms
    @route.kilometry / @time.sek.to_f
  end

  def wezly
    @route.milemorskie / @time.hour.to_f
  end
end


# zle trzeba zmienic zeby bral 2 predkosci i czas i guess
class Przyspieszenie
  def initialize(km1, sek1, km2, sek2, delsek)
    @delta = Czas.new(delsek)
    @speed1 = Predkosc.new(km1, sek1)
    @speed2 = Predkosc.new(km2, sek2)
  end

  def kms2
    (@speed2.kms - @speed1.kms) / @delta.sek
  end

  def mmh2
    (@speed2.wezly - @speed1.wezly) / @delta.hour
  end
end


s = "km/h"
print s.ljust(13), "wezly\n"
for a in 1..5 do
    x = rand(100)
    y = rand(2000)
    p = Predkosc.new(x, y)
    print p.kmh.round(2).to_s.ljust(13), p.wezly.round(2), "\n"
end

print "\n"

s = "km/s^2"
print s.ljust(13), "mm/h^2\n"
for a in 1..5 do
    s1 = rand(100000)
    t1 = rand(2000)
    s2 = rand(100000)
    t2 = rand(2000)
    dt = rand(1000)
    c = Przyspieszenie.new(s1, t1, s2, t2, dt)
    print c.kms2.round(2).to_s.ljust(13), c.mmh2.round(2), "\n"
end

