def main():
    n = 1001
    half = n // 2
    a = [[0] * n for _ in range(n)]

    c = (half, half)
    a[half][half] = cnt = 1

    r = 2
    for _ in range(half):
        x = c[0]
        y = c[1] + 1
        for i in range(r):
            cnt += 1
            a[x + i][y] = cnt

        x = x + r - 1
        y = x - 1
        for i in range(r):
            cnt += 1
            a[x][y - i] = cnt

        x = x - 1
        y = y - r + 1
        for i in range(r):
            cnt += 1
            a[x - i][y] = cnt

        x = x - r + 1
        y = y + 1
        for i in range(r):
            cnt += 1
            a[x][y + i] = cnt

        c = (c[0] - 1, c[1] + 1)
        r += 2

    s = -1
    for i in range(n):
        s += a[i][i] + a[i][n - i - 1]

    print(s)


if __name__ == "__main__":
    main()
