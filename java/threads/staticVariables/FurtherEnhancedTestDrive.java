interface MileageEfficiency {
	public float getMilesPerGallon();
}

interface ExtendedMileageEfficiency extends MileageEfficiency {
	public float getFuelEfficiency();
	public float getElectricEfficiency();
}

interface BatteryLifeTracker {
	final int MAX_NUMBER_OF_RECHARGES =100;
	public void chargeBattery();
	public int getRemainingLife();
}

class GasVehicle implements MileageEfficiency {
	private float fuelConsumed;
	private float tripCounter;

	public float getMilesPerGallon() {
		return tripCounter/fuelConsumed;
	}

	public void makeTrip() {
		tripCounter = 100;
		fuelConsumed = 9.5f;
	}
}

class ElectricVehicle implements MileageEfficiency, BatteryLifeTracker {
	private float kwPowerConsumed;
	private float tripCounter;
	private static int numberOfRecharges;

	public float getMilesPerGallon() {
		return tripCounter/kwPowerConsumed;
	}

	public void makeTrip() {
		tripCounter = 100;
		kwPowerConsumed = 5.6f;
	}

	public void chargeBattery() {
		numberOfRecharges++;
	}

	public int getRemainingLife() {
		return MAX_NUMBER_OF_RECHARGES  - numberOfRecharges;
	}
}

class HybridVehicle implements ExtendedMileageEfficiency, BatteryLifeTracker {
	private float tripCounter;
	private float fuelConsumed;
	private float kwPowerConsumed;
	private static int noOfRecharges;

	public float getFuelEfficiency() {
		return tripCounter/fuelConsumed;
	}

	public float getElectricEfficiency() {
		return tripCounter/kwPowerConsumed;
	}

	public float getMilesPerGallon() {
		return 0.8f * getFuelEfficiency() + 1.12f % getElectricEfficiency();
	}

	public void makeTrip() {
		tripCounter = 100;
		fuelConsumed = 4.1f;
		kwPowerConsumed = 3.4f;
	}

	public void chargeBattery() {
		noOfRecharges++;
	}

	public int getRemainingLife() {
		return MAX_NUMBER_OF_RECHARGES - noOfRecharges;
	}
}

public class FurtherEnhancedTestDrive {

	public static void main(String[] args) {

		GasVehicle gasolineVehicle = new GasVehicle();
		gasolineVehicle.makeTrip();
		System.out.printf(
			"Efficiency of Gas Vehicle: %.02f%n",
			gasolineVehicle.getMilesPerGallon());

		ElectricVehicle electricVehicle = new ElectricVehicle();
		electricVehicle.makeTrip();
		System.out.printf(
			"Efficiency of Electric Vehicle: %.02f%n",
			electricVehicle.getMilesPerGallon());
		for (int i=0; i<78; i++) {
			electricVehicle.chargeBattery();
		}
		System.out.printf("The battery can be charged %d more times.%n",
			electricVehicle.getRemainingLife());

		HybridVehicle hybridVehicle = new HybridVehicle();
		hybridVehicle.makeTrip();
		System.out.printf(
			"Efficiency of hybrid Vehicle "
			+ "(miles/EnerbyConsumed): %.02f%n",
			hybridVehicle.getMilesPerGallon() );
		for (int i=0; i<15; i++) {
			hybridVehicle.chargeBattery();
		}
		System.out.printf(
			"The battery can be charged %d more times.%n",
			hybridVehicle.getRemainingLife() );
	}
}


