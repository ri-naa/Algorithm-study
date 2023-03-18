import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int x = scanner.nextInt();
		int y = scanner.nextInt();
		int w = scanner.nextInt();
		int h = scanner.nextInt();
		
		int x_min=x; int y_min=y;
		
		if(x>w-x) 
			x_min = w-x;	
		if(y>h-y)
			y_min = h-y;
		
		if(x_min<y_min)
			System.out.print(x_min);
		else
			System.out.print(y_min);

	}

}