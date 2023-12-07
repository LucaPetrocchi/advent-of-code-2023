import re
f = open('./day1input.txt', 'r')

total = 0
nums = {
    'one': '1',
    'two': '2',
    'three': '3',
    'four': '4',
    'five': '5',
    'six': '6',
    'seven': '7',
    'eight': '8',
    'nine': '9',
}    

def replaceByDict(inStr: str, rep: dict) -> str: 
    for item in list(rep.keys()):
        pos = [i.start() for i in re.finditer(item, inStr)]
        if pos is not None:
            for x in range(len(pos)):
                inStr = inStr[:pos[x]+x+1] + rep[item] + inStr[pos[x]+x+1:]
    return inStr

for line in f:
    replaced = replaceByDict(line, nums)
    match = ''.join(re.findall(r'[0-9]+', replaced))
    add = f'{match[0]}{match[-1]}'
    total += int(add)

print(total)