list1 = ["a", "c", "d", "b", "b", "c", "a", "d", "c", "b", "a", "d"]

# O(N)
def groupArray(list):
    hashTable = {}
    newList = []

    for char in list:
        try:
            if hashTable[char]:
                hashTable[char] += 1
        except:
            hashTable[char] = 1
            continue
    
    for key, count in hashTable.items():
        for n in range(0, count):
            newList.append(key)

    return newList
    


print(list1)
print(groupArray(list1))