package test_01;

class Caaa{
	public int num1;
	public int num2;
}

class Cbbb extends Caaa{
	public void set_num(int x , int y) {
		this.num1 = x; 
		this.num2 = y;				
	}
	public void set_show() {
		System.out.println("num1 = " + this.num1);
		System.out.println("num2 = " + this.num2);
	}	
}
public class test_01 {
	public static void main(String[] args) {
		Cbbb bb = new Cbbb();
		bb.set_num(5, 10);
		bb.set_show();
	}
}