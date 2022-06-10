list1 = [5,3,3,7]; list2 = [4,1,1,6]

def sumSwap(list1, list2):
    
    hashTable = {} #Hash table to store values of first array:
    sum1,sum2 = 0,0

    for num in list1:
        # Get sum of first array, while storing its values in a hash table, together with an index
        sum1 += num
        hashTable[num] = list1.index(num)

    for num in list2:
        sum2 += num
    
    # Calculate how much a number in the second array needs to shift by:
    shift_amount = (sum1 - sum2)/2  

    # Iterate over each number in second array:
    for num in list2:
        # Check hash table for the number's counterpart in the first array, which is calculated as the current number plus the amount it has to shift by:
        try:
            if hashTable[num+shift_amount]:
                list3 = [hashTable[num+shift_amount], list2.index(num)] # list of [3,0]
                list1[list3[0]], list2[list3[1]] = list2[list3[1]], list1[list3[0]] # swap both elements
                return 
        except KeyError:
            continue

    return None


print(sum(list1), sum(list2))
sumSwap(list1, list2)
print(sum(list1), sum(list2))