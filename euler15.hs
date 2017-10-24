choose :: (Integral a) => a -> a -> a
choose n k = foldl (\z i -> (z * (n-i+1)) `div` i) 1 [1..k]

main = print $ choose (20 + 20) 20
