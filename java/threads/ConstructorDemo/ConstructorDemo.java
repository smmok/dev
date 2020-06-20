class Vehicle {
	private int numWheels;
	private String color;
	
	public Vehicle(int w, String c) {
		numWheels = w;
		color = c;
	}

	public Vehicle(Vehicle other) {
		this(other.getNumWheels(), other.getColor());
	}

	public int getNumWheels() {
		return numWheels;
	}

	public String getColor() {
		return color;
	}
}

class Truck extends Vehicle {
	private boolean articulated;

	public Truck(int w, String c) {
		super(w,c);
		articulated = false;
	}

	public Truck(int w, String c, boolean art) {
		this(w,c);
		articulated = art;
	}

	public Truck(Truck other) {
		this(other.getNumWheels(), other.getColor(), other.getArticulated());
	}

	public boolean getArticulated() {
		return articulated;
	}
}


class ConstructorDemo {
	
	public static void main(String[] args) {
		
		Vehicle v = new Vehicle(4,"Red");
		System.out.println(display(v.getNumWheels(), v.getColor()));

		Vehicle vdup = v;
		System.out.println(display(vdup.getNumWheels(), vdup.getColor()));

		Truck t = new Truck(18,"White",true);
		System.out.println(
			display(t.getNumWheels(), t.getColor(), t.getArticulated()));

		Truck t1 = new Truck(6,"Black");
		System.out.println(
			display(t1.getNumWheels(), t1.getColor(), t1.getArticulated()));

		Truck tdup = t;
		System.out.println(
			display(tdup.getNumWheels(), tdup.getColor(), tdup.getArticulated()));
		
	}

	public static String display(int numWheels, String color) {
		String str = "Wheels=" + numWheels + " Color=" + color;
		return str;
	}

	public static String display(int numWheels, String color, boolean art) {
		String str = display(numWheels, color);
		str = str + " Articulated=" + art;
		return str;
	}

}
