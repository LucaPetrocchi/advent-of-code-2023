import re

f = open('./day1input.txt', 'r')
total = 0
for line in f:
    match = ''.join(re.findall(r'[0-9]+', line))
    add = f'{match[0]}{match[-1]}'
    total += int(add)

print(total)
