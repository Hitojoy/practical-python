# bounce.py
#
# Exercise 1.5

Height = 100
Count = 1
while Height > 1:
    Height = 3 / 5 * Height
    print(Count, round(Height, ndigits = 4))
    Count += 1

