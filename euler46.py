from math import *
from utils import *

MAX_N = 10000

def conjecture_holds(primes, odd):
    i, l = 0, len(primes)
    while primes[i] < odd and i < l:
        if sqrt((odd - primes[i]) / 2).is_integer():
            return True
        i += 1
    return False

def main():
    primes = [p for p in sieve(MAX_N)][1:]
    odd_composites = gen_odd_composites(primes)

    for odd in odd_composites:
        if not conjecture_holds(primes, odd):
            print (odd)
            break

if __name__ == "__main__":
    main()
