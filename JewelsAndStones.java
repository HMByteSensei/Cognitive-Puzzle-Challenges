class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        HashSet<Character> skup = new HashSet<>();
        for(int i=0; i<jewels.length(); i++) {
            skup.add(jewels.charAt(i));
        }
        
        int counter = 0;
        for(int i=0; i<stones.length(); i++) {
            if(skup.contains(stones.charAt(i))) {
                counter = counter + 1;
            }
        }
        return counter;
    }
}
