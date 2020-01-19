from utils import *

def main():
    s = 0
    for num in range(1, 1000000, 2):
        if is_palindrome(str(num)) and is_palindrome(bin(num)[2:]):
            s += num
    print (s)

if __name__ == "__main__":
    main()
