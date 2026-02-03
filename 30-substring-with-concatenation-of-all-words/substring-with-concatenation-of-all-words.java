import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> result = new ArrayList<>();
        if (s == null || words == null || words.length == 0) return result;

        int wordLen = words[0].length();
        int totalWords = words.length;
        int totalLen = wordLen * totalWords;

        if (s.length() < totalLen) return result;

        // Frequency map of words
        Map<String, Integer> wordCount = new HashMap<>();
        for (String w : words) {
            wordCount.put(w, wordCount.getOrDefault(w, 0) + 1);
        }

        // Try all possible starting offsets
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int count = 0;
            Map<String, Integer> seen = new HashMap<>();

            for (int right = offset; right + wordLen <= s.length(); right += wordLen) {

                String curr = s.substring(right, right + wordLen);

                if (wordCount.containsKey(curr)) {
                    seen.put(curr, seen.getOrDefault(curr, 0) + 1);
                    count++;

                    // Too many occurrences → shrink window
                    while (seen.get(curr) > wordCount.get(curr)) {
                        String leftWord = s.substring(left, left + wordLen);
                        seen.put(leftWord, seen.get(leftWord) - 1);
                        left += wordLen;
                        count--;
                    }

                    // Found valid concatenation
                    if (count == totalWords) {
                        result.add(left);
                    }

                } else {
                    // Invalid word → reset
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }

        return result;
    }
}
