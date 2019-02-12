while True:
    h = int(input("height:"))
    if 0 < h < 23:
        break

w = 2 * (h + 2)
def main():
    for l in range(h+1):
        for p in range(w):
            if setblock(h, l, p):
                print('#', end = '')
            else:
                print('.', end = '')
        print('')

def setblock(hei, line, pos):
    if pos >= hei - line and pos <= hei:
        return True
    elif pos >= hei + 3 and pos <= hei + line +3:
        return True
    else:
        return False

main()