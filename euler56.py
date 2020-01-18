def main():
    print(max(
        sum(map(int, str(a ** b))) for a in range(100) for b in range(100)
    ))


if __name__ == "__main__":
    main()
