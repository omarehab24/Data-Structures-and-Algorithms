list1 = [3,-4,4,-3,5,-9]

# Find the max number
def max(list1):
    max = list1[0]

    for num in list1:
        if num > max:
            max = num

    return max

print(max(list1))

# As you can see, the first line of our function assumes the first number in the array is the greatest_number. Now, this is a “greedy” assumption. That is, we’re declaring the first number to be the greatest_number because it’s the greatest number we’ve encountered so far.


# Find the subsection with the greatest sum
def maxSum(list1):
    current_sum, greatest_sum = 0,0

    for num in list1:
        if current_sum + num < 0:
            current_sum = 0
        else:
            current_sum += num
    
        # Greedily assume the current sum is the greatest sum if it's the greatest sum we've encountered so far:
        if current_sum > greatest_sum:
            greatest_sum = current_sum
    
    return greatest_sum


print(maxSum(list1))