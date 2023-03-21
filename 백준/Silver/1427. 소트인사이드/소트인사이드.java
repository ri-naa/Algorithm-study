import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String num = sc.next();
		
		int list[] = new int[num.length()];
		for(int i=0; i<num.length(); i++) {
			list[i] = num.charAt(i)-'0';
		}
		
		
		int most, temp;
		for(int i=0; i<num.length()-1; i++) {
			most = i;
			
			for(int j=i; j<num.length(); j++)
				if(list[j]>list[most]) most = j;
			
			temp = list[i];
			list[i] = list[most];
			list[most] = temp;

		}
		
		for(int i=0; i<num.length(); i++) {
			System.out.print(list[i]);
		}

	}

}