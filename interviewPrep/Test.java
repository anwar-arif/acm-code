
class A {
	final public void run() {
		System.out.println("A run called") ;
	}
}

class B  {
	static int st = 0 ;
	int var = 0 ;
	public void run() {
		System.out.println("B run called") ;
	}

	public static void jump() {
		System.out.println("Jump called") ;
	}

	public static void move() {
		System.out.println("B static method called st = " + st ) ;

		jump() ;
	}
}


public class Test {
	public static void main(String[] args ) {		
		B b = new B() ;
		b.run() ;
		b.move() ;
	}
}