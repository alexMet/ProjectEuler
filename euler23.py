from utils import *

MAX_N = 28124

def main():
    abundants = []
    for i in range(2, MAX_N):
        if i < sum(factors(i) - {i}):
            abundants += [i]

    l = len(abundants)
    abus = set()
    for i in range(l):
        for j in range(i, l):
            s = abundants[i] + abundants[j]
            if s >= MAX_N: break
            abus.add(s)

    print (sum(range(1, MAX_N)) - sum(abus))

if __name__ == "__main__":
    main()
