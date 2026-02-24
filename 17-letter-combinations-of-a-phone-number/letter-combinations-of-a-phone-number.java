import java.util.*;

class Solution {
    
    public List<String> letterCombinations(String digits) {
        
        List<String> result = new ArrayList<>();
        
        if(digits.length() == 0){
            return result;
        }

        String[] phoneMap = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(result, phoneMap, digits, "", 0);

        return result;
    }

    public void backtrack(List<String> result, String[] phoneMap,
                          String digits, String current, int index){

        if(index == digits.length()){
            result.add(current);
            return;
        }

        String letters = phoneMap[digits.charAt(index) - '0'];

        for(char c : letters.toCharArray()){
            backtrack(result, phoneMap, digits,
                      current + c, index + 1);
        }
    }
}