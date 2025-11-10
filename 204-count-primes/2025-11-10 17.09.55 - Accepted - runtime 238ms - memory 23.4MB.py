class Solution(object):
    def countPrimes(self, n):
        if n < 3:
            return 0
        sieve = bytearray(b'\x01') * n
        sieve[0:2] = b'\x00\x00'
        for i in range(2, int(n ** 0.5) + 1):
            if sieve[i]:
                sieve[i * i:n:i] = b'\x00' * len(sieve[i * i:n:i])
        return sum(sieve)
