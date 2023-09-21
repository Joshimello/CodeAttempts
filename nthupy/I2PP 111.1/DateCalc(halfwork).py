from datetime import datetime, timedelta

class days:
    def __init__(self, d):
        self.delta = timedelta(days=d)
    
    def __repr__(self):
        return f'days({self.delta.days})'
    
    def __add__(self, other):
        if isinstance(other, datetime):
            return other + self.delta
        else:
            raise TypeError('Cannot add days to a non-datetime object')
    
    def __radd__(self, other):
        return self + other
    
    def __sub__(self, other):
        if isinstance(other, datetime):
            return other - self.delta
        else:
            raise TypeError('Cannot subtract days from a non-datetime object')
    
    def __rsub__(self, other):
        return other - self.delta

class weeks:
    def __init__(self, w):
        self.delta = timedelta(weeks=w)
    
    def __repr__(self):
        return f'weeks({self.delta.days // 7})'
    
    def __add__(self, other):
        if isinstance(other, datetime):
            return other + self.delta
        else:
            raise TypeError('Cannot add weeks to a non-datetime object')
    
    def __radd__(self, other):
        return self + other
    
    def __sub__(self, other):
        if isinstance(other, datetime):
            return other - self.delta
        else:
            raise TypeError('Cannot subtract weeks from a non-datetime object')
    
    def __rsub__(self, other):
        return other - self.delta

class months:
    def __init__(self, m):
        self.m = m
    
    def __repr__(self):
        return f'months({self.m})'
    
    def __add__(self, other):
        if isinstance(other, datetime):
            year = other.year
            month = other.month + self.m
            if month > 12:
                year += month // 12
                month = month % 12
            return datetime(year, month, other.day)
        elif isinstance(other, months):
            return months(self.m + other.m)
        else:
            raise TypeError('Cannot add months to a non-datetime or non-months object')
    
    def __radd__(self, other):
        return self + other
    
    def __sub__(self, other):
        if isinstance(other, months):
            return months(self.m - other.m)
        else:
            raise TypeError('Cannot subtract a non-months object from months')
    
def datecalc(*args):
    stack = []
    for arg in args:
        if isinstance(arg, str):
            if arg == 'add':
                A = stack.pop()
                B = stack.pop()
            elif arg == 'sub':
                A = stack.pop()
                B = stack.pop()
                stack.append(B-A)
            elif arg == 'swap':
                A = stack.pop()
                B = stack.pop()
                stack.append(A)
                stack.append(B)
            elif arg == 'today':
                stack.append(datetime.today())
            elif arg == 'tomorrow':
                stack.append(datetime.today() + timedelta(days=1))
            elif arg == 'yesterday':
                stack.append(datetime.today() - timedelta(days=1))
            else:
                try:
                    stack.append(datetime.strptime(arg, '%Y-%m-%d'))
                except ValueError:
                    raise ValueError(f'Invalid date string: {arg}')
        elif isinstance(arg, days) or isinstance(arg, weeks) or isinstance(arg, months):
            stack.append(arg)
        else:
            raise TypeError(f'Invalid argument: {arg}')
    return stack


print(datecalc('today', 'tomorrow', 'yesterday', days(4)))
print(datecalc('today', 'tomorrow', 'yesterday', days(4), 'add'))
# datecalc('today', months(2), 'add')
# datecalc('today', date(2019, 12, 10), date(2019, 12, 20), 'sub', 'add')
# datecalc('today', weeks(2), 'add', months(2), 'swap','sub')
