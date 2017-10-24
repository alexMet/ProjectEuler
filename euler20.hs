count_digits 0 acc = acc
count_digits x acc = count_digits (div x 10) ((mod x 10) : acc)

main = print $ sum $ count_digits (product [1..100]) []
