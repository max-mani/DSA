class Solution {
public:
    string smallestNumber(string num, long long t) {

        // =========================================================
        // PART 1: Factorize t
        // =========================================================

        int needed_2 = 0;
        int needed_3 = 0;
        int needed_5 = 0;
        int needed_7 = 0;

        long long temp = t;

        while (temp % 2 == 0) {
            needed_2++;
            temp /= 2;
        }

        while (temp % 3 == 0) {
            needed_3++;
            temp /= 3;
        }

        while (temp % 5 == 0) {
            needed_5++;
            temp /= 5;
        }

        while (temp % 7 == 0) {
            needed_7++;
            temp /= 7;
        }

        // t contains a prime factor other than 2, 3, 5, or 7.
        // No digit from 1 to 9 can provide that factor.
        if (temp > 1)
            return "-1";


        // =========================================================
        // PART 2: DP
        //
        // dp[i][j] =
        // minimum number of digits required to provide
        // at least 2^i * 3^j
        // =========================================================

        int dp[47][30];

        for (int i = 0; i < 47; i++) {
            for (int j = 0; j < 30; j++) {
                dp[i][j] = 1e9;
            }
        }

        dp[0][0] = 0;

        // Contributions of digits:
        //
        // 2 -> (1,0)
        // 3 -> (0,1)
        // 4 -> (2,0)
        // 6 -> (1,1)
        // 8 -> (3,0)
        // 9 -> (0,2)

        int trans[6][2] = {
            {1, 0}, // 2
            {0, 1}, // 3
            {2, 0}, // 4
            {1, 1}, // 6
            {3, 0}, // 8
            {0, 2}  // 9
        };

        for (int i = 0; i < 47; i++) {
            for (int j = 0; j < 30; j++) {

                if (dp[i][j] == 1e9)
                    continue;

                for (auto &it : trans) {

                    int n1 = min(46, i + it[0]);
                    int n2 = min(29, j + it[1]);

                    dp[n1][n2] =
                        min(dp[n1][n2], dp[i][j] + 1);
                }
            }
        }

        // Convert "exactly" into "at least".
        for (int i = 46; i >= 0; i--) {
            for (int j = 29; j >= 0; j--) {

                if (i < 46)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j]);

                if (j < 29)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            }
        }


        // =========================================================
        // PART 3: Prime-factor contribution of every digit
        // =========================================================

        int f2[] = {
            0, 0, 1, 0, 2,
            0, 1, 0, 3, 0
        };

        int f3[] = {
            0, 0, 0, 1, 0,
            0, 1, 0, 0, 2
        };

        int f5[] = {
            0, 0, 0, 0, 0,
            1, 0, 0, 0, 0
        };

        int f7[] = {
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0
        };


        // =========================================================
        // PART 4: Find first zero and check if num itself works
        // =========================================================

        int n = num.size();

        bool hasZero = false;
        int firstZero = n;

        for (int i = 0; i < n; i++) {

            if (num[i] == '0') {
                hasZero = true;
                firstZero = i;
                break;
            }
        }

        // If num has no zero, check whether it is already valid.
        if (!hasZero) {

            int r2 = needed_2;
            int r3 = needed_3;
            int r5 = needed_5;
            int r7 = needed_7;

            for (char c : num) {

                int d = c - '0';

                r2 = max(0, r2 - f2[d]);
                r3 = max(0, r3 - f3[d]);
                r5 = max(0, r5 - f5[d]);
                r7 = max(0, r7 - f7[d]);
            }

            if (r2 == 0 &&
                r3 == 0 &&
                r5 == 0 &&
                r7 == 0) {

                return num;
            }
        }


        // =========================================================
        // PART 5: Find the rightmost position we can increase
        // =========================================================

        int limit = min(firstZero, n - 1);

        // Prime-factor contribution of the prefix
        // before position 'i'.
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        int p7 = 0;

        for (int i = 0; i < limit; i++) {

            int d = num[i] - '0';

            p2 += f2[d];
            p3 += f3[d];
            p5 += f5[d];
            p7 += f7[d];
        }

        // Try positions from right to left.
        for (int i = limit; i >= 0; i--) {

            int start = num[i] - '0' + 1;

            // Try every larger digit.
            for (int d = start; d <= 9; d++) {

                // What factors are still missing
                // after taking the prefix + candidate digit?
                int need2 =
                    max(0, needed_2 - p2 - f2[d]);

                int need3 =
                    max(0, needed_3 - p3 - f3[d]);

                int need5 =
                    max(0, needed_5 - p5 - f5[d]);

                int need7 =
                    max(0, needed_7 - p7 - f7[d]);

                // Number of positions remaining after d.
                int L = n - i - 1;

                // Can the remaining positions satisfy
                // all remaining requirements?
                if (need5 + need7 + dp[need2][need3] <= L) {

                    // -------------------------------------------------
                    // PART 6: Build the smallest possible suffix
                    // -------------------------------------------------

                    string ans = num.substr(0, i);

                    // Put our chosen larger digit.
                    ans += char('0' + d);

                    int rem2 = need2;
                    int rem3 = need3;
                    int rem5 = need5;
                    int rem7 = need7;

                    // Fill the remaining positions.
                    for (int pos = 0; pos < L; pos++) {

                        for (int x = 1; x <= 9; x++) {

                            int n2 =
                                max(0, rem2 - f2[x]);

                            int n3 =
                                max(0, rem3 - f3[x]);

                            int n5 =
                                max(0, rem5 - f5[x]);

                            int n7 =
                                max(0, rem7 - f7[x]);

                            int remainingSlots =
                                L - pos - 1;

                            // Check whether choosing x still
                            // allows us to finish the suffix.
                            if (n5 + n7 + dp[n2][n3]
                                <= remainingSlots) {

                                ans += char('0' + x);

                                rem2 = n2;
                                rem3 = n3;
                                rem5 = n5;
                                rem7 = n7;

                                break;
                            }
                        }
                    }

                    return ans;
                }
            }

            // Move one position to the left.
            //
            // The prefix for the next iteration loses
            // num[i-1].
            if (i > 0) {

                int d = num[i - 1] - '0';

                p2 -= f2[d];
                p3 -= f3[d];
                p5 -= f5[d];
                p7 -= f7[d];
            }
        }


        // =========================================================
        // PART 7: No same-length answer exists.
        //
        // Construct the smallest valid number with more digits.
        // =========================================================

        int minLen =
            needed_5 +
            needed_7 +
            dp[needed_2][needed_3];

        int len = max(n + 1, minLen);

        string ans = "";

        int rem2 = needed_2;
        int rem3 = needed_3;
        int rem5 = needed_5;
        int rem7 = needed_7;

        for (int pos = 0; pos < len; pos++) {

            for (int x = 1; x <= 9; x++) {

                int n2 =
                    max(0, rem2 - f2[x]);

                int n3 =
                    max(0, rem3 - f3[x]);

                int n5 =
                    max(0, rem5 - f5[x]);

                int n7 =
                    max(0, rem7 - f7[x]);

                int remainingSlots =
                    len - pos - 1;

                if (n5 + n7 + dp[n2][n3]
                    <= remainingSlots) {

                    ans += char('0' + x);

                    rem2 = n2;
                    rem3 = n3;
                    rem5 = n5;
                    rem7 = n7;

                    break;
                }
            }
        }

        return ans;
    }
};