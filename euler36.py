from utils import *

def main():
    s = 0
    for num in range(1, 1000000, 2):
        if isPalindrome(str(num)) and isPalindrome(bin(num)[2:]):
            s += num
    print (s)

if __name__ == "__main__":
    main()
