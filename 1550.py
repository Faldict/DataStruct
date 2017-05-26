#!usr/bin/env python
n = raw_input()
water = raw_input()
water = eval(water)
sum = 0
p = 0
n = int(n)
# print n, len(water)

for i in range(1, n-1):
    left = max(water[0: i])
    right = max(water[i+1: n])
    top = min(left, right)
    if top > water[i]:
        sum += top - water[i]

print sum