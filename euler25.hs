fib_indx x = fib 1 1 3
 where fib one two acc = 
    let thre = one + two
    in if thre >= x then acc
       else fib two thre (acc+1)

main = print $ fib_indx (10 ^ 999)
