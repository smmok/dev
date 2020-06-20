class EThread extends Thread {
	
	EThread() {
		super("RThread");
		System.out.println("RThread: "+this);
		start();
	}

	public void run() {
		try {
			for (int i=5; i>0; i--) {
				System.out.println("Extended thread: "+i);
				Thread.sleep(100);
			}
		} catch (InterruptedException e) {
			System.out.println("Extended thread interrupted");
		} System.out.println("Extended thread exiting.");
	}
}


