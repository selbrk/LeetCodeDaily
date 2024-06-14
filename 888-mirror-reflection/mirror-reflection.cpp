class Solution {
public:
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a*b) / gcd(a,b);
    }
    int mirrorReflection(int p, int q) {
        // q m = p n => m = lcm(p,q) / q && n = lcm(p,q) / p
        // ex 1: lcm(2,1) = 2 => m = 2, n = 2 / 2 = 1

        // ex 2: lcm(3,1) = 3 => m = 3, n = 1

        int m = lcm(p,q) / q;
        int n = lcm(p,q) / p;

        if(m % 2 && n % 2)
            return 1;
        if(n % 2)
            return 2;
        return 0;


    }
};