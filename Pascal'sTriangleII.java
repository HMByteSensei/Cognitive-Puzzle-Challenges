
class Solution {
    public List<Integer> getRow(int n) {
        List<Integer> res = new ArrayList<>(n + 1);

        for (int i = 0; i < n + 1; i++) {
            res.add(1);
        }
        for(int i=1; i<n+1; i++) {
            for(int j=i; j>0; j--) {
                if(j == i) {
                    res.set(i, 1);
                } else {
                    res.set(j, res.get(j) + res.get(j-1));
                }
            }
        }
        return res;
    }
}
