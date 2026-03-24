class Solution:
    MOD = 10**9 + 7

    def power(self, base, exp):
        result = 1
        base %= self.MOD
        
        while exp > 0:
            if exp % 2 == 1:
                result = (result * base) % self.MOD
            
            base = (base * base) % self.MOD
            exp //= 2
        
        return result

    def countGoodNumbers(self, n: int) -> int:
        even = (n + 1) // 2
        odd = n // 2
        
        return (self.power(5, even) * self.power(4, odd)) % self.MOD
        