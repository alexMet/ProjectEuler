from utils import is_prime


def main():
    cnt = 1
    step = 2
    prime_cnt = 0
    total_cnt = 1
    percent = 1.0

    while percent >= 0.1:
        for i in range(3):
            cnt += step
            if is_prime(cnt):
                prime_cnt += 1

        cnt += step
        step += 2
        total_cnt += 4
        percent = prime_cnt / total_cnt

    print("Cube", step - 1, "Percentage", percent)


if __name__ == "__main__":
    main()
