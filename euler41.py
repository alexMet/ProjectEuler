from itertools import *
from utils import *

# 1+2+3+4+5+6+7+8+9 = 45 always dividable by 3
# 1+2+3+4+5+6+7+8   = 36 always dividable by 3
def main():
    evens = ['2', '4', '6', '8']
    nums = '7654321'
    primes = [p for p in sieve(int(nums) + 2)]

    for i in range(len(nums)):
        for p in permutations(nums[i:]):
            if p[i - 1] not in evens:
                prime = int("".join(p))
                if is_prime(primes, prime):
                    print (prime)
                    return

if __name__ == "__main__":
    main()
