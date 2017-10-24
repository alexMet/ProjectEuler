from utils import *

def main():
    cnt_factors = [len(set(prime_factors(i))) for i in range(2, 6)]
    i = 6
    while True:
        cnt_factors.pop(0)
        cnt_factors += [len(set(prime_factors(i)))]
        if all(cnt == 4 for cnt in cnt_factors):
            print (i - 3)
            return
        i += 1

if __name__ == "__main__":
    main()
