# FUNCTIONS
## sum data nubmers func
def sumAllNumbers(data):
    willingToReturn = 0
    for f in data:
        willingToReturn += int(f)
    return willingToReturn

## output the result number into one file func
def outputFile(res):
    fo = open("result.txt", 'w')
    fo.write(str(res))
    fo.close()


# VARIABLES
data = []


# LOAD FILE
fl = open('id.txt', 'r')
while (True):
    willingToInput = fl.readline()
    if willingToInput == '':
        break
    data.append(willingToInput[0:2])

print(sumAllNumbers(data))
outputFile(sumAllNumbers(data))


# CLOSE F STAFF
fl.close()
