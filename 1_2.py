class Solution:
	def twoSum(self,nums,target):
		dict={}
		if not nums:
			return []
		for i in range(len(nums)):
			dict[str(nums[i])] = i
		for i in range(len(nums)):	
			complement = target - nums[i]
			if str(complement) in dict and  int(dict.get(str(complement))) != i:
				return [i,dict.get(str(complement))]
		return "No two sum solution"
print(Solution.twoSum('a',[3,2,4],6))