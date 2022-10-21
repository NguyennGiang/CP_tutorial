package L01;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();
        int m = sc.nextInt();
        String A = s.substring(n - 1, n);
        String B = s.substring(m - 1, m);
        String ans = s.substring(0, n - 1);
        ans = ans + B + s.substring(n, m - 1);
        ans = ans + A + s.substring(m);
        System.out.print(ans);
    }
}
