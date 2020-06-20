class TestNotify {
	public static void main(String args[]) {
		Q q = new Q();
		new Subprogram(q);

		for (int i=0; i<100; i++)
			System.out.print("i="+i+" ");
		System.out.println("i=END");

		q.setter();
		System.out.println("Main Exiting.");
	}
}

class Q {
	synchronized void waiter() {
		try {
			System.out.println("Waiter now waiting using: wait()");
			wait();
		} catch (InterruptedException e) {
			System.out.println("IE Caught");
		}
	System.out.println("*********Waiter Out of Waiting**********");
	}

	synchronized void setter() {
		System.out.println("Setter activating notify()");
		notify();
    }
}


class Subprogram implements Runnable {

	Q q;

	Subprogram(Q q){
		this.q = q;
		new Thread(this,"Subprogram Started").start();
	}

	public void run() {
		q.waiter();
    }
}
	
	
