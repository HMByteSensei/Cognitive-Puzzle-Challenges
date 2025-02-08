class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> mapa = new HashMap<>();
        int longest = 0;
        int start = 0; // This will track the start index of the current substring

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            
            // If the character is already in the map and its index is within the current window
            if (mapa.containsKey(currentChar) && mapa.get(currentChar) >= start) {
                // Move the start index to one past the previous index of the current character
                start = mapa.get(currentChar) + 1;
            }
            
            // Update the map with the current character's index
            mapa.put(currentChar, i);
            
            // Update the length of the longest substring found so far
            longest = Math.max(longest, i - start + 1);
        }

        return longest;
    }
}
