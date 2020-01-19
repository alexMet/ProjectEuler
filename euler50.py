from utils import sieve, in_primes

LIMIT = 10 ** 6


def main():
    sums = []
    prime_sum = 0
    primes = [p for p in sieve(LIMIT)]

    for p in primes:
        prime_sum += p
        sums += [prime_sum]

    maxlen = 0
    number = 0
    for index, s in enumerate(sums):
        if s < LIMIT and in_primes(primes, s):
            maxlen = index
            number = s

        for i in range(index - maxlen - 1, -1, -1):
            sr = s - sums[i]

            if sr >= LIMIT:
                break

            if in_primes(primes, sr):
                maxlen = index - i
                number = sr

    print("Prime =", number, "Longest chain =", maxlen)


if __name__ == "__main__":
    main()
