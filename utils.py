from functools import reduce
from math import floor, sqrt, ceil


def is_palindrome(word):
    l = len(word)
    for i in range(ceil(l / 2)):
        if word[i] != word[l - i - 1]:
            return False
    return True


def sieve(limit):
    a = [True] * limit
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i * i, limit, i):
                a[n] = False


def is_prime(n):
    if n <= 3:
        return n > 1
    elif n % 2 == 0 or n % 3 == 0:
        return False
    else:
        r = floor(sqrt(n))
        f = 5

        while f <= r:
            if n % f == 0 or n % (f + 2) == 0:
                return False
            f += 6

    return True


def binary_search(l, value):
    low = 0
    high = len(l) - 1

    while low <= high:
        mid = (low + high) // 2
        if l[mid] > value:
            high = mid-1
        elif l[mid] < value:
            low = mid+1
        else:
            return mid

    return -1


def in_primes(primes, value):
    return binary_search(primes, value) != -1


def gen_odd_composites(primes):
    i, odd, l = 0, 3, len(primes)
    odd_composites = []

    while odd < MAX_N and i < l:
        while odd != primes[i]:
            odd_composites += [odd]
            odd += 2
        i += 1
        odd += 2

    return odd_composites


def factors(n):
    return set(reduce(
        list.__add__,
        ([i, n // i] for i in range(1, int(sqrt(n) + 1)) if n % i == 0)
    ))


def prime_factors(n):
    step = lambda x: 1 + (x << 2) - ((x >> 1) << 1)
    maxq = int(floor(sqrt(n)))
    d = 1
    q = n % 2 == 0 and 2 or 3

    while q <= maxq and n % q != 0:
        q = step(d)
        d += 1

    return q <= maxq and [q] + prime_factors(n // q) or [n]


def count_change(coins, m, change):
    table = [0 for k in range(change + 1)]
    table[0] = 1

    for i in range(0, m):
        for j in range(coins[i], change + 1):
            table[j] += table[j - coins[i]]

    return table[change]


def is_triagonal(x):
    n = (sqrt(8 * x + 1) - 1) / 2
    return n.is_integer()


def is_pentagonal(x):
    n = (sqrt(24 * x + 1) + 1) / 6
    return n.is_integer()


def is_hexagonal(x):
    n = (sqrt(8 * x + 1) + 1) / 4
    return n.is_integer()


def champernowne_digit(n):
    i = 0

    while True:
        start = 10 ** i
        i += 1
        digits = i * 9 * start

        if n <= digits:
            number = start + ceil(n / i) - 1
            index = n % i
            return int(str(number)[index - 1])

        n -= digits
