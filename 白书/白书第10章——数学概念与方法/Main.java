package uva;

import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		BigInteger ans[]=new BigInteger[1005];
		ans[1]=BigInteger.ZERO;
		for(int i=2;i<=1000;i++) {
			ans[i]=ans[i-1].multiply(BigInteger.valueOf(2));
			if(i%2==0)ans[i]=ans[i].add(BigInteger.ONE);
			else ans[i]=ans[i].subtract(BigInteger.ONE);
		}
		while(in.hasNextInt()) {
			System.out.println(ans[in.nextInt()]);
		}
	}

}
