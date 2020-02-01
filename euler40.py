from utils import champernowne_digit


def main():
    ans = 1

    for i in range(7):
        ans *= champernowne_digit(10 ** i)

    print(ans)


if __name__ == "__main__":
    main()
