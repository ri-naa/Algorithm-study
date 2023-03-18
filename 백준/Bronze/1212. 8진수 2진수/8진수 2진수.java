import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		String s = scanner.next();
		
		for(int i=0; i<s.length(); i++) {
			String a = Integer.toBinaryString(s.charAt(i)-'0');
			if(a.length()==2 && i!=0)
				a="0"+a;
			else if(a.length()==1 && i!=0)
				a="00"+a;
			sb.append(a);
		}
		System.out.println(sb);
		
	}

}
