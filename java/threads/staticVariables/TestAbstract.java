interface Modem {
	public int read();
	public int write();
	public void init();
}

abstract class AbstractModem implements Modem {
	public int read() {
		int bytesRead=10;
		return bytesRead;
	}

	public int write() {
		int bytesWritten=20;
		return bytesWritten;
	}
}

interface WirelessModem extends Modem {
	public String name = "Wireless Modem";
	public String getName();
}

interface Origin extends Modem {
	public String country = "USA";
	public String getOrigin();
}

abstract class CellPhone implements Modem, WirelessModem, Origin {

	public int read() {
		int bytesRead=10;
		return bytesRead;
	}

	public int write() {
		int bytesWritten=20;
		return bytesWritten;
	}
}

class HayesModem extends AbstractModem {
	public void init() {
		System.out.printf("Hayes Modem Initiated.%n");
	}
}

class NewHayesModem extends HayesModem {
	public void printer() {
		System.out.println("NewHayesModem");
	}
}

class NewHayesModem2 extends NewHayesModem {
	public void printer2() {
		System.out.println("NewHayesModem2");
	}
}

class Telephone {
	public String name = "ATT";
	public String getName() {
		return name;
	}
}

class VerizonPhone extends CellPhone {
	public void init() {
		System.out.printf("Verizon Phone Initiated.%n");
	}

	public String getName() {
		return name;
	}

	public String getOrigin() {
		return country;
	}
}

class TestAbstract {

	public static void main(String[] args) {

		HayesModem modem = new HayesModem();
		modem.init();
		System.out.println("Read: " + modem.read() + 
			" Written: " + modem.write() );

		NewHayesModem modem2 = new NewHayesModem();
		modem2.init();
		System.out.println("Read: " + modem2.read()+1 + 
			" Written: " + modem2.write()+1 );

		NewHayesModem2 modem22 = new NewHayesModem2();
		modem22.init();
		System.out.println("Read: " + modem22.read()+2 + 
			" Written: " + modem22.write()+2 );

		Telephone tel = new Telephone();
		System.out.println("Name=" + tel.getName());

		VerizonPhone phone = new VerizonPhone();
		phone.init();
		System.out.println("Read:" + phone.read() +
			" Written:" + phone.write() + " Name:" + phone.getName() +
			" Origin:" + phone.getOrigin() );
    }
}
