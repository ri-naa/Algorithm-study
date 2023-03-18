import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int n = scanner.nextInt();
		int num = 4*(n-1)+1;
		int center = 2*n-1;
		
		char star[][]= new char[num][num];
		for(int i=0; i<num; i++) {
			for(int j=0; j<num; j++) {
				star[i][j]=' ';
			}
		}
		
		for(int cnt=0; cnt<n; cnt++) {
			for(int i=center-2*cnt-1; i<center+2*cnt; i++) {
				for(int j=center-2*cnt-1; j<center+2*cnt; j++) {
					if(i==center-2*cnt-1 || j==center-2*cnt-1 || i==center+2*cnt-1 || j==center+2*cnt-1)
						star[i][j]='*';
				}
			}
		}
		
		for(int i=0; i<num; i++) {
			for(int j=0; j<num; j++) {
				System.out.print(star[i][j]);
			}
			System.out.println();
		}

	}

}
