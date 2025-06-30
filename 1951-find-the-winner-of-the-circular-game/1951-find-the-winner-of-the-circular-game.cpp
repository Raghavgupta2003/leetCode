class Solution {
public:
    int win(int n, int k) {
        if (n == 1) return 0; // Base case: only one person remains
        return (win(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        int idx = win(n, k);
        return idx + 1; // Convert from 0-based to 1-based index
    }
};
