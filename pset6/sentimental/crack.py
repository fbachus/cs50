from crypt import crypt

keyhash = input('Which hash shall be bruteforced? ')
#inpt = input('please give a test password to crack: ')
#keyhash = crypt(inpt, '50')

def main():
    key = [' ']
    end = 52**5
    for i in range(end):
        leng = len(key)
        tryhash = crypt(translate(key, leng),'50')

        if tryhash == keyhash:
            print(f'the key is {translate(key, leng)}')
            return 0
        if i % 10303 == 0:
            print(translate(key, leng))
            print(key, i)

        if 'z' in key:
            ind = key.index('z')
            if ind + 1 is leng:
                key.append(' ')
            key[ind+1] = increase_char(key[ind+1])
            #for cha in range(leng):
             #   if key[cha] is 'z':
              #      if cha+1 is len(key):
               #         key.append(' ')
                #    key[cha +1] = increase_char(key[cha+1])
                 #   key[cha] = increase_char(key[cha])
                  #  break

        key[0] = increase_char(key[0])

    print('nothing was found')


def increase_char(chariter):
    if ((chariter >= 'A' and chariter < 'Z') or (chariter >= 'a' and chariter < 'z')):
        chariter = chr(ord(chariter) + 1)
    elif chariter is  'Z':
        chariter = 'a'
    else:
        chariter = 'A'
    return chariter


def translate(arr, leng):
    transtr = ''
    for i in range(leng):
        transtr += arr[i]
    return transtr

main()

