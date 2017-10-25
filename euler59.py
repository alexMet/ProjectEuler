import string

def isPrintable(txt):
    return (all(c in string.printable for c in txt))

def decipher(cipher):
    error = 0
    for a in string.ascii_lowercase:
        for b in string.ascii_lowercase:
            for c in string.ascii_lowercase:
                ans = ""
                key = [a, b, c]

                for i in range(len(cipher)):
                    ans += chr(ord(key[i % 3]) ^ cipher[i])

                if isPrintable(ans) and "the" in ans and "and" in ans:
                    print ("Key is =", a + b + c)
                    print ("Sum is =", sum([ord(c) for c in ans]))
                    print (ans)

def main():
    cipher = [int(c) for c in input().split(",")]
    decipher(cipher)

if __name__ == "__main__":
    main()
