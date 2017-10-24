loopb a 100 acc = ((a^100):acc)
loopb a b acc = loopb a (b+1) ((a^b):acc)

loopa 101 acc2 = acc2
loopa a acc2 = loopa (a+1) (loopb a 2 acc2)

out _ [] acc4 = acc4
out e (y:ys) acc4 = if (e==y) then out e ys acc4 
            else out e ys (y:acc4)

remove [] acc3 = acc3
remove (x:xs) acc3 = remove (out x xs []) (x:acc3)

main = print $ length (remove (loopa 2 []) [])
