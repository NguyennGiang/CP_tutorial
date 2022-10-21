package L01;

import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[4 * n];
        int res = 1;
        for (int i = 0; i < 4 * n - 1; i++){
            a[sc.nextInt()-1]++;
        }
        for (int i = 0; i < 4 * n; i++){
            if(a[i] == 3){
                System.out.print(i + 1);
            }
        }
    }
}
