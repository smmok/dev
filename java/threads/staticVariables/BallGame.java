class Ball {
	private static int count = 0;

	public static int getCount() {
		return count;
	}

	public Ball() {
		count++;
	}
}

public class BallGame {

	public static void main(String[] args) {

		for (int i=0; i<1000; i++) {
		   new Ball();
		}
		System.out.println("No of Balls created: " + Ball.getCount());
	}
}


