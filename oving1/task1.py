
def is_fibonacci_number(n : int):
    a = 0
    b = 1
    while (b < n):
        temp = b
        b += a
        a = temp
    return b == n
    