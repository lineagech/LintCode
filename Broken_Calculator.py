class Solution:
    def brokenCalc(self, X: 'int', Y: 'int') -> 'int':
        step = 0
        while Y > X:
            step += 1
            if Y % 2 == 0:
                Y /= 2
            else:
                Y = (Y+1)
        return step + int(X-Y)
