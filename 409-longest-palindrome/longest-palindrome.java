class Solution {
    public int longestPalindrome(String s) {
        boolean odd = false;
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if(map.containsKey(c))
                map.replace(c, map.get(c) + 1);
            else
                map.put(c, 1);
        }
        int ans = 0;
        for(Character c : map.keySet()) {
            Integer value = map.get(c);
            if(value % 2 != 0) {
                odd = true;
                value--;
            }
            ans += value;
        }

        if(odd)
            ans++;
        
        return ans;

    }
}