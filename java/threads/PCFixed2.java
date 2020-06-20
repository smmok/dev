class PCFixed2 {
	public static void main(String args[]) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		System.out.println("Ctrl-C to exit");
	}
}

class Q {
	int n;
	boolean valueSet=false;

	synchronized int get() {
		while(!valueSet) {
			try {
				wait();
			} catch(InterruptedException e) {
				System.out.println("IE caught");
			}
		}		
		System.out.println("Got: "+n);
		valueSet = false;
		notify();
		return n;
	}

	synchronized void set(int k) {
		while(valueSet) {
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("IE caught");
			}
		}
		this.n = k;
		System.out.println("Set: "+n);
		valueSet = true;
		notify();
	}
}

class Producer implements Runnable {
	Q q;
	
	Producer(Q q) {
		this.q=q;
		new Thread(this,"Producer").start();
	}

	public void run() {
		int i=0;
		while(true) {
			q.set(i++);
		}
	}
}

class Consumer implements Runnable {
	Q q;

	Consumer(Q q) {
		this.q=q;
		new Thread(this,"Consumer").start();
	}

	public void run() {
		while(true) {
			q.get();
		}
	}
}

		


