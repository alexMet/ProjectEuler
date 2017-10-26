import re

# a perfect square never ends in 2, 3, 7 or 8
# a perfect square never ends in odd number of zeros
# a perfect square will always have a digital root of 0, 1, 4 or 7

# numbers that have a square ending with 900 arein the form of *30 or *70
def check_square(n):
    if re.match("1\d2\d3\d4\d5\d6\d7\d8\d900", str(n ** 2)) != None:
        print (n)

def main():
    start = 20 + int(int("1{}2{}3{}4{}5{}6{}7{}8{}900".format(0, 0, 0, 0, 0, 0, 0, 0)) ** 0.5)
    end   = int(int("1{}2{}3{}4{}5{}6{}7{}8{}900".format(9, 9, 9, 9, 9, 9, 9, 9)) ** 0.5)

    for i in range(start, end, 100):
        check_square(i)
        check_square(i + 40)

if __name__ == "__main__":
    main()
