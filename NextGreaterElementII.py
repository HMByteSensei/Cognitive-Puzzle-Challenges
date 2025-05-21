def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = []
        res = [-1] * len(nums)
        for i in range(2):
            for j in range(len(nums)):
                while(stack and stack[-1][0] < nums[j]):
                    _, second = stack.pop()
                    res[second] = nums[j]
                stack.append((nums[j], j))
        return res
