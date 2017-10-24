from fractions import Fraction

def main():
    f = Fraction(1, 2)
    cnt = 0

    for i in range(1000): 
        f = 1 / (2 + f)
        newf = 1 + f
        cnt += len(str(newf.numerator)) > len(str(newf.denominator))
    print (cnt)

if __name__ == "__main__":
    main()
