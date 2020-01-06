from utils import is_pentagonal


def main():
    i = 1
    pentagonals = []

    while True:
        penta = i * (3 * i - 1) // 2

        for p in pentagonals:
            if is_pentagonal(penta - p) and is_pentagonal(penta + p):
                print(penta - p)
                return

        i += 1
        pentagonals += [penta]


if __name__ == "__main__":
    main()
