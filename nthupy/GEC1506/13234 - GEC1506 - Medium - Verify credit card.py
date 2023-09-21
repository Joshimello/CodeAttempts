while True:
  try:
    NUMS = []
    CARD = input()[::-1]
    for i, n in enumerate(CARD):
      if i % 2:
        NUMS.append(str(int(n) * 2))
      else:
        NUMS.append(n)

    for i, n in enumerate(NUMS):
      if len(n) > 1:
        NUMS[i] = sum(map(int, list(n)))
        # print(NUMS[i])

    SUM = sum(map(int, NUMS))

    # print(SUM)

    if SUM % 10 == 0:
      print(CARD[::-1])

  except EOFError:
    break