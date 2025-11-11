class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i, j, carry = len(num1) - 1, len(num2) - 1, 0
        res = []

        ord0 = ord('0')
        append = res.append

        while i >= 0 or j >= 0 or carry:
            if i >= 0:
                carry += ord(num1[i]) - ord0
                i -= 1
            if j >= 0:
                carry += ord(num2[j]) - ord0
                j -= 1
            append(chr(carry % 10 + ord0))
            carry //= 10

        res.reverse()
        return ''.join(res)
