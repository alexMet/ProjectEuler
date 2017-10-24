#!/bin/python3
from utils import *

def main():
    change = 200
    coins = [1, 2, 5, 10, 20, 50, 100, 200]
    print (count_change(coins, len(coins), change))

if __name__ == "__main__":
    main()
