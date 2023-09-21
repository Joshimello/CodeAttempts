BASE = int(input())

while True:
  try:
    CARD, CCV = input().split(',')
    SUM = sum(map(int, CARD.split(' ')))

    ENC = ''
    for POW in range(0, 100)[::-1]:
      CONST = 0
      while True:
        if SUM < (BASE ** POW) * (CONST + 1):
          break
        CONST += 1
      SUM -= (BASE ** POW) * CONST
      ENC += str(CONST)
      # print(CONST, POW)

    # print(ENC)

    ENC = ENC[-6:]
    NEW = ENC[0] + ENC[2] + ENC[4]

    # print(NEW)

    if NEW == CCV:
      print('corrent')
    else:
      print('incorrect')

  except EOFError:
    break