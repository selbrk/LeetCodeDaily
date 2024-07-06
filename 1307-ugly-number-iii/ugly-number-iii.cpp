class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

    long long f(long long x, long long a, long long b, long long c) {
        return x / a + x / b + x / c -
               (x / lcm(a, b) + x / lcm(a, c) + x / lcm(b, c)) +
               x / lcm(a, lcm(b, c));
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        /*
        If the number x is an ugly number, then there are n ugly numbers up to
        this number. The count of multiples of a up to x is x / a, the count of
        multiples of b is x / b, and the count of multiples of c is x / c. The
        count of multiples of both a and b is x / lcm(a,b), the count of
        multiples of both a and c is x / lcm(a,c), and the count of multiples of
        both b and c is x / lcm(b,c). The count of multiples of a, b, and c is x
        / lcm(a,b,c). Using the principle of inclusion-exclusion, if the number
        x is an ugly number, n = x / a + x / b + x / c - (x / lcm(a,b) + x /
        lcm(a,c) + x / lcm(b,c)) + x / lcm(a,b,c).

        For example, for n = 2, we can check that indeed 4 = 6 / 2 + 6 / 3 + 6 /
        4 - 6 / 6 - 6 / 4 - 6 / 12 + 6 / 12 However, there are many such
        numbers, which one should we choose? The one that is divisible by at
        least one of a, b, c. This is the smallest x that satisfies the
        equation. Therefore, to find the answer, we can apply binary search on
        the function f(x) = x / a + x / b + x / c - (x / lcm(a,b) + x / lcm(a,c)
        + x / lcm(b,c)) + x / lcm(a,b,c).
        */
        long long l = 0, r = INT_MAX;
        while (l < r) {
            long long x = (l + r) / 2;
            long long cand = f(x, a, b, c);
            if (cand >= n)
                r = x;
            else
                l = x + 1;
        }
        return l;
    }
};
