from utils import is_hexagonal, is_pentagonal


def main():
    i = 1
    cnt = 0

    while True:
        triangular = i * (i + 1) // 2

        if is_pentagonal(triangular) and is_hexagonal(triangular):
            print(triangular)
            cnt += 1

            if cnt == 3:
                return

        i += 1


if __name__ == "__main__":
    main()
