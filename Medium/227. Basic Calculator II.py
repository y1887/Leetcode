# https://regexone.com/references/python
# http://120.105.184.250/cswang/thit/Linux/RegularExpression.htm
# https://ithelp.ithome.com.tw/articles/10197315

import re
class Solution:
    def calculate(self, s: str) -> int:
        remove = ['']
        tmp1 = re.split('\s|\W+', s)
        tmp2 = re.split("\s|\d+", s)
        nums = [i for i in tmp1 if i not in remove]
        op = [i for i in tmp2 if i not in remove]
        
        print(nums)
        print(op)
        
        i = 0
        while (i < len(op)):
            if (op[i] == '*'):
                a = int(nums[i])
                b = int(nums[i+1])
                nums.pop(i)
                nums.pop(i)
                op.remove('*')
                nums.insert(i, a*b)
                #print(nums)
                #print(op)
            elif (op[i] == '/'):
                a = int(nums[i])
                b = int(nums[i+1])
                nums.pop(i)
                nums.pop(i)
                op.remove('/')
                nums.insert(i, int(a/b))
                #print(nums)
                #print(op)
            else:
                i += 1;
                
        if (len(op) > 0):
            for i in op:
                a = int(nums[0])
                b = int(nums[1])
                nums.pop(0)
                nums.pop(0)
                if (i == '+'):
                    nums.insert(0, a+b)
                else:
                    nums.insert(0, a-b)
                    
        return nums[0]
'''
Runtime: 4248 ms, faster than 5.01% of Python3 online submissions for Basic Calculator II.
Memory Usage: 19.3 MB, less than 7.28% of Python3 online submissions for Basic Calculator II.
'''