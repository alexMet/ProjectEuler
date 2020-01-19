from utils import *

def rotate(l, n):
    return l[n:] + l[:n]

def main():
    n = 10 ** 6
    primes = [p for p in sieve(n)]
    checked = {i:False for i in range(n)}
    total_cnt = 0

    for p in primes:
        if checked[p]: continue

        rot = set()
        p_str = str(p)
        p_len = len(p_str)
        for i in range(p_len):
            p_str = rotate(p_str, 1)
            p_int = int(p_str)
            if in_primes(primes, p_int):
                rot.add(p_int)
                checked[p_int] = True
            else:
                break

        if i == p_len - 1:
            total_cnt += len(rot)

    print (total_cnt)

if __name__ == "__main__":
    main()
