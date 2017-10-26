import java.util.Scanner;

public class Absum{
	public static void main(String arg[]){
		Scanner scanner = new Scanner(System.in);
		System.out.printf("请输入两个整数: ");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		
		System.out.printf("%d + %d = %d", a, b, a + b);
	}
}
