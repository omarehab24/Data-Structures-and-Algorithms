
list1 = [2, 0, 4, 5, 3, 8]


def twoSum(array):
    hashTable = {}

    for i in array:
        try:
            if hashTable[10 - i]:
                return True
        except KeyError:
            hashTable[i] = True
            continue    

    return False



print(twoSum(list1))
