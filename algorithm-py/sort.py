def sort_bubble():
    nums = [int(i) for i in input().split(',')]
    length = len(nums)

    for i in range(length-1):
        for j in range(length-i-1):
            if nums[j] > nums[j+1]:
                temp = nums[j]
                nums[j]=nums[j+1]
                nums[j+1]=temp

    print(nums)

def sort_order():
    nums = [int(i) for i in input().split(',')]
    length = len(nums)

    for i in range(length-1):
        min_flag = i
        for j in range(i+1,length):
            if nums[j]<nums[min_flag]:
                min_flag = j
        if min_flag!=i:
            temp = nums[i]
            nums[i] = nums[min_flag]
            nums[min_flag] = temp
    print(nums)

def sort_insert():


if __name__ == '__main__':
    # sort_bubble()
   sort_order()