class Solution:
	def twoSum(self,nums,target):
		if not nums:
			return []
		for i in range(len(nums)):
			for j in range(i,len(nums)):
				if nums[i] + nums[j] == target and i != j:
					return [i,j]
		return "No two sum solution"
print(Solution.twoSum('a',[3,2,4],6))