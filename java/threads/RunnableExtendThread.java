class ChildThread extends Thread {

	String threadname;
	
	ChildThread(String _threadname) {
		super(_threadname+"-Extend Thread");
		System.out.println(_threadname+"-Extend Thread "+this);
		threadname = _threadname;
		start();
	}

    public void run() {
		try {
			for (int i=5; i>0; i--) {
				System.out.println(threadname+"-Extend Thread "+i);
				Thread.sleep(100);
			}
		} catch(InterruptedException e) {
			System.out.println(threadname+"-Extend Interrupted.");
		} System.out.println(threadname+"-Extend Exiting");
	}
}


class RunnableThread implements Runnable {

	Thread t;
	String tname;
	int duration;

	RunnableThread(String threadname,int _duration) {
		t = new Thread(this,threadname);
		tname=threadname;
		duration = _duration;
		System.out.println(threadname+" "+this);
		t.start();
	}

	public void run() {
		try {
			for (int i=5; i>0; i--) {
				System.out.println(tname+" "+i);
				Thread.sleep(duration);
			}
		} catch (InterruptedException e) {
			System.out.println(tname+" Runnable Interrupted");
		} System.out.println(tname+" Runnable Exiting");
	}
}

	
