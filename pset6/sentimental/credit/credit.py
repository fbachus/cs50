def main():
    number = str(input("Number:"))
    lenum = len(number)
    if (lenum != 13) and (lenum != 15) and (lenum != 16):
        print("INVALID")
        return 0
    if checksum(number):
        print("The credit card is valid and belongs to")
        print(determinecompany(number))
    else: print("INVALID")
    return 0
    

def determinecompany(num):
    numdex = num[0:2]
    if ((numdex == '34') or numdex == '37'):
        return "AMEX"
    elif ((numdex == '51') or (numdex == '52') or (numdex == '53') or (numdex == '54') or (num[0:2] == '55')):
        return "MASTERCARD"
    elif num[0] == '4':
        return "VISA"
    else:
        return "INVALID"


def checksum(num):
    oddnums, evennums = [], []
    oddnums0 = int(num[1::2])*2
    evennums0 = num[0::2]
    oddstrings = str(oddnums0)
    oddsums, evensums = 0, 0
    for o in oddstrings:
        oddnums.append(int(o))
    for e in evennums0:
        evennums.append(int(e))
    for i in range(len(oddnums)):
        oddsums += oddnums[i]
    for i in range(len(evennums)):
        evensums += evennums[i]

    sums = oddsums + evensums
    
    if sums % 10 == 0:
        return True
    else:
        return False


# example credit card number: 378282246310005

main()