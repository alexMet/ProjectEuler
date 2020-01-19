from itertools import *
from utils import *

def main():
    four_digit_primes = []

    for p in sieve(10000):
        if 1000 <= p <= 9999: four_digit_primes += [p]
        if p >= 9999: break

    for p in four_digit_primes:
        sec = p + 3330
        thr = p + 3330 + 3330

        if in_primes(four_digit_primes, p) and in_primes(four_digit_primes, sec) and in_primes(four_digit_primes, thr):
            p_permu = ["".join(x) for x in permutations(str(p))]
            if str(sec) in p_permu and str(thr) in p_permu: print (p, sec, thr)

if __name__ == "__main__":
    main()
