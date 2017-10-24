#!/bin/python3
from utils import *

def main():
    change = 100
    coins = [i for i in range(1, change)]
    print (count_change(coins, len(coins), change))

if __name__ == "__main__":
    main()
