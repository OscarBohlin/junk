import hashlib
from math import *
import sys

def win_getpass(prompt='Password: ', stream=None):
    """Prompt for password with echo off, using Windows getch()."""
    if sys.stdin is not sys.__stdin__:
        return fallback_getpass(prompt, stream)
    import msvcrt
    for c in prompt:
        msvcrt.putwch(c)
    pw = ""
    while 1:
        c = msvcrt.getwch()
        if c == '\r' or c == '\n':
            break
        if c == '\003':
            raise KeyboardInterrupt
        if c == '\b':
            if pw == '':
                pass
            else:
                pw = pw[:-1]
                msvcrt.putwch('\b')
                msvcrt.putwch(" ")
                msvcrt.putwch('\b')
        else:
            pw = pw + c
            msvcrt.putwch("*")
    msvcrt.putwch('\r')
    msvcrt.putwch('\n')
    return pw




def file_to_dict(file):
    o = open(file,"r")
    d = {}
    for line in o:
        k, v = line.strip().split(":")
        d[k] = v
    return d


# passwd test if a password has its hash in the specified file
# Input, password a string woth the user password
# Input, filename, a file were the hashes are stored, one hash per line
# Output, True if password exist in filename, otherwise False
def passwd(username, password, filename):
    d = file_to_dict(filename)
    if username in d:
        hash = d[username]
        a = hashlib.sha256(str.encode(password)).hexdigest()
        return (hash == a)
    else:
        print("Invalid username")
        return False


def exist_username(username, filename):
    d = file_to_dict(filename)
    if username in d:
        return True
    else:
        return False


def hash_password():
    while True:
        username = input("Enter the username you whish to use:")
        ans = exist_username(username, "pwd.txt")
        if (ans == False):
            print ("Invalid username")
        else: break

    nr_tries = 0
    while nr_tries < 3:
        print("You have a maximum of", 3 - nr_tries, "tries, enter password:")
        password = win_getpass("")
        if (passwd(username, password, "pwd.txt") == True):
            print("Correct password")
            return True
        else:
            nr_tries = nr_tries + 1
    return False


 # Main program starts here
if (hash_password() == False):
    quit()

while True:

    def Q(TheList):
        if len(TheList) % 2 == 0:
            p = 0
        else:
            p = 1
        if len(TheList) < 2:
            return 0

        TheList.sort()
        median_pos = len(TheList) // 2
        ql = TheList[:median_pos]
        qh = TheList[median_pos + p:]
        return (median(ql),median(qh))

    def typv(TheList):
        dict = {}
        for e in TheList:
            element = str(e)
            if element in dict:
                dict[element] = dict[element] + 1
            else:
                dict[element] = 1
        result = []
        best_value_so_far = 0
        for d in dict.items():
            if d[1] >= best_value_so_far:
                best_value_so_far = d[1]
                if d[1] > best_value_so_far:
                    result = []
                result.append(d[0])
        return (result, best_value_so_far)

    def median(TheList):
        TheList.sort()
        if len(TheList) == 1:
            return TheList[0]
        if len(TheList) == 0:
            return 0
        if len(TheList) % 2 == 0:                                                               #Funktion för jämna tal
            pos1 = len(TheList) // 2
            pos2 = pos1 -1
            return ((TheList[pos1] + TheList[pos2]) / 2.0)
        else:
            return TheList[len(TheList) // 2]


    def mean(TheList):
        summa = 0
        for element in TheList:
            summa += element
        return summa/len(TheList)

    def divation(TheList):
        if len(TheList) <= 1:
            print("Cannot calculate deviation, need more than two elements")
            return 0
        xm = mean(TheList)
        summa = 0
        for element in TheList:
            summa += pow(element - xm,2)
        return sqrt(summa / (len(TheList)-1))

    L = []

    print("Hello There!")
    while True:
        number = input("What numbers do you want to add?:")
        if (number==""): break
        L.append(float(number))
    if len(L) == 0:
        print("Error: no data to calculate")
        exit(-1)
        break
    L.sort()
    print("Min = ", L[0])
    print("Max = ", L[len(L)-1])
    print("Range = ", max(L) - min(L))
    print("Mean = ", mean(L))
    print("Median = ", median(L))
    print("Standard deviation = ", divation(L))
    print("Mode =", typv(L)[0])
    print("The mode appears", typv(L)[1], "number of times")
    y = Q(L)
    if len(L) < 2:
        print("Cannot calculate Q1,Q3. Need more then two values")

    if y != 0:
        print("Q1 = ",y[0])
        print("Q3 = ",y[1])
        print("Interquartile = ", y[1] - y[0])

    answer = input("Press enter to reboot the programme, any other buttom will terminate the programme")
    if (answer==""): continue
    else:
        print("Terminating")
        break

