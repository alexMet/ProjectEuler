from utils import *

def main():
    f = lambda n, a, b : n * n + a * n + b
    maxn, c1, c2 = 0, 0, 0
    primes = [p for p in sieve(10000000)]
    bees = [b for b in range(3, 1000, 2)]

    for b in bees:
        if not in_primes(primes, b): continue

        for a in range(-b, 1000, 2):
            n = 1
            while in_primes(primes, f(n, a, b)): n += 1
            if n > maxn: maxn, c1, c2 = n, a, b

    print (c1, c2)
    print (maxn)
    print (c1 * c2)

if __name__ == "__main__":
    main()
