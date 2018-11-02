class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s == "":
        	return 0;

        s_length = len(s)
        str_number = ""
        for i in range(0,s_length):
        	str_number += "1"
        for i in range(1,s_length):
        	b = int(str_number[i-1])
        	for j in range(1,b+1):
        		if s[i-j] == s[i]:
        			str_number[i] = str(j+1)
        		break
        return str_number
print(Solution.lengthOfLongestSubstring('a',"wqsdwdq"))