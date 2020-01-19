from utils import *

def isTruncatable(primes, p):
    str_p = str(p)
    l = len(str_p)
    for i in range(1, l):
        if not (in_primes(primes, int(str_p[i:])) and in_primes(primes, int(str_p[:i]))):
            return False

    return True

def main():
    primes = [p for p in sieve(1000000)]
    total_sum = cnt = 0

    for p in primes[4:]:
        if isTruncatable(primes, p):
            cnt += 1
            total_sum += p
            print (cnt, p)
            if cnt == 11: break
    print (total_sum)

if __name__ == "__main__":
    main()
