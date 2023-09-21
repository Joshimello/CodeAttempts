from re import search

def is_strong(passwd):
    if len(passwd) < 8:
        return False
    if search(r'[a-z]', passwd) == None:
        return False
    if search(r'[A-Z]', passwd) == None:
        return False
    if search(r'[0-9]', passwd) == None:
        return False
    if search(r'[-!@#$%^&*()+]', passwd) == None:
        return False
    if search(r'(.)\1', passwd) != None:
        return False
    return True

T = int(input())
for t in range(T):
    passwd = input()
    if is_strong(passwd):
        print('Strong')
    else:
        print('Weak')