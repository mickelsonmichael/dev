
def divideBy(n):
    try:
        return 420 / n
    except ZeroDivisionError:
        print("Infinity")
    except:
        print("Unknown error")

print(divideBy(2))
print(divideBy(4))
print(divideBy(0))
print(divideBy(10))
