// Q. How we came up with this idea of two states like state 1- last two are of same color
//                                    state 2- last two are of different colors
// so this is the real intution of this problem.
//   now we figure out our ans in below explanation.
//explanation:

//  Reduce Information (Key DP Skill)

// At the end, there are only 3 possibilities:

// Last 1 color → A
// Last 2 same → AA
// Last 2 different → AB

// But notice:

// Case A (just 1 element) behaves same as AB
// → because no restriction yet

// Final Insight → Only 2 States Needed

// Now we realize:

// ✅ State 1: same
// Last two are same → AA
// Dangerous state (next same is forbidden)
// ✅ State 2: diff
// Last two are different → AB
// Safe state (can do anything)

// Shortcut Thinking (Exam / Interview Trick)

// If constraint is:

// “No 2 same” → track last 1
// “No 3 same” → track last 2
// “No k same” → track last k−1

// Define DP Table

// We already discovered 2 states:

// same[i] → ways to paint i posts ending with same color
// diff[i] → ways to paint i posts ending with different colors

// So we create arrays:

// same[n+1], diff[n+1]
// 🧱 Step 2: Fill Base Cases

// Start from smallest:

// i = 1
// Only 1 post → no “same/diff” concept
// same[1] = 0;
// diff[1] = k;
// i = 2
// same[2] = k;           // AA
// diff[2] = k * (k - 1); // AB
// 🔁 Step 3: Fill Table (Bottom-Up)

// Now build from i = 3 → n

// From intuition:

// same[i] = diff[i-1];
// diff[i] = (same[i-1] + diff[i-1]) * (k - 1);
// 🧾 Step 4: Final Answer
// same[n] + diff[n]
// 🚀 Full Tabulation Code
class Solution {
public:
    int countWays(int n, int k) {
        if (n == 1) return k;

        vector<long long> same(n + 1), diff(n + 1);

        // Base cases
        same[2] = k;
        diff[2] = k * (k - 1);

        // Fill table
        for (int i = 3; i <= n; i++) {
            same[i] = diff[i - 1];
            diff[i] = (same[i - 1] + diff[i - 1]) * (k - 1);
        }

        return same[n] + diff[n];
    }
};
