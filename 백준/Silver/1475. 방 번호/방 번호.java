import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		String s = scanner.next();
		
		int num[] = new int[9];
		
		for(int i=0; i<s.length(); i++) {
			int a = s.charAt(i)-'0';
			if(a==6 || a==9) {
				num[6]+=1;
			}
			else
				num[a]+=1;
		}
		
		num[6] = (num[6]+1)/2;
		
		int max=num[0];
		for(int i=0; i<9; i++) {
			if(max<num[i]) max=num[i];
		}
		System.out.println(max);

	}

}
