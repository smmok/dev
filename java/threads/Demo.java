class Demo {
	public static void main(String args[]) {
		new EThread();
		//new RThread();

		try {
			for (int i=5; i>0; i--) {
				System.out.println("Main thread:"+i);
				Thread.sleep(150);
			}
		} catch(InterruptedException e) {
			System.out.println("Main thread interrupted.");
		} System.out.println("Main thread exiting.");
	}
}

