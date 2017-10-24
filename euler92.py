def sum_digit_squares(n):
    return sum(map(lambda c: int(c) ** 2, str(n)))

def main():
    max_n = 10 ** 7
    nums = [0] * max_n

    for i in range(1, max_n):
        if nums[i] != 0: continue

        j = i
        while (j != 1 and j != 89):
            j = sum_digit_squares(j)

            if j < max_n and nums[j] != 0:
                nums[i] = nums[j]
                break

        if nums[i] == 0: nums[i] = j

    print (len(list(filter(lambda x: x == 89, nums))))

if __name__ == "__main__":
    main()
