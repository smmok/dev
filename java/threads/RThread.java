class RThread implements Runnable {
	
	Thread t;

	RThread() {
		t = new Thread(this,"RThread");
		System.out.println("RThread: "+t);
		t.start();
	}

	public void run() {
		try {
			for (int i=5; i>0; i--) {
				System.out.println("Runnable thread: "+i);
				Thread.sleep(100);
			}
		} catch (InterruptedException e) {
			System.out.println("Runnable thread interrupted");
		} System.out.println("Runnable thread exiting.");
	}
}


