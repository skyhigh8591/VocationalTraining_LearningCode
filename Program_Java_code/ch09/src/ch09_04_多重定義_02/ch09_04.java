package ch09_04_�h���w�q_02;

class MyClass {
	int age;
	String name;

	MyClass(int a) {
		age = a;
	}

	MyClass(String str) {
		name = str;
	}

	MyClass(int a, String str) {
		age = a;
		name = str;
	}

	void printInfo() {
		System.out.println(name);
		System.out.println(age);
		System.out.println("\\\\\\\\\\\\");
	}
}

public class ch09_04 {

	public static void main(String[] args) {
		MyClass A = new MyClass(20);
		A.printInfo();
		MyClass B = new MyClass("John");
		B.printInfo();
		MyClass C = new MyClass(25, "Lin");
		C.printInfo();

	}

}
