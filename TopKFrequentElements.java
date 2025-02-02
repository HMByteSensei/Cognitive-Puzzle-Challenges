import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> mapa = new HashMap<>();
        for (int n : nums) {
            mapa.put(n, mapa.getOrDefault(n, 0) + 1);
        }

        // Create a TreeMap sorted by frequency
        TreeMap<Integer, List<Integer>> mapa2 = new TreeMap<>(Collections.reverseOrder());
        for (Map.Entry<Integer, Integer> entry : mapa.entrySet()) {
            int frequency = entry.getValue();
            int number = entry.getKey();
            mapa2.putIfAbsent(frequency, new ArrayList<>());
            mapa2.get(frequency).add(number);
        }

        // Prepare the result array
        int[] rez = new int[k];
        int index = 0;
        Iterator<Map.Entry<Integer, List<Integer>>> it = mapa2.entrySet().iterator();
        while (it.hasNext() && index < k) {
            Map.Entry<Integer, List<Integer>> entry = it.next();
            List<Integer> numbers = entry.getValue();
            for (int num : numbers) {
                if (index < k) {
                    rez[index++] = num;
                } else {
                    break;
                }
            }
        }
        
        return rez;
    }
}
