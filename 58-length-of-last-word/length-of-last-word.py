class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        wrd=s.split();
        return len(wrd[-1])
        