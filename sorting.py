def f(nums):
	nums=list(map(int, nums.split(', ')))
	swapped = True
	while swapped:
		swapped = False
		for i in range(len(nums) - 1):
			if nums[i] > nums[i + 1]:
				nums[i], nums[i + 1] = nums[i + 1], nums[i]
				swapped = True
	return nums
a=input("Enter the numbers separated by commas: ")
print("The list of numbers is in ascending order: ", f(a))