class Demo {
	public static void main(String args[]) {
		//EThread t1 = new EThread();
		//new RThread();
		RunnableThread t1 = new RunnableThread("One",200);
		RunnableThread t2 = new RunnableThread("Two",150);
		RunnableThread t3 = new RunnableThread("Three",100);

		System.out.println("Thread One started is alive: "+t1.t.isAlive());
		System.out.println("Thread Two started is alive: "+t2.t.isAlive());
		System.out.println("Thread Three started is alive: "+t3.t.isAlive());
				
		try {
			t1.t.join();
			t2.t.join();
			t3.t.join();
		} catch(InterruptedException e) {
			System.out.println("Main thread interrupted.");
		}

		try {
			for (int i=5; i>0; i--) {
				System.out.println("Main thread:"+i);
				Thread.sleep(150);
			}
		} catch(InterruptedException e) {
			System.out.println("Main thread interrupted.");
		} System.out.println("Main thread exiting.");

		System.out.println("Thread One alive: "+t1.t.isAlive());
		System.out.println("Thread Two alive: "+t2.t.isAlive());
		System.out.println("Thread Three alive: "+t3.t.isAlive());

	}
}

