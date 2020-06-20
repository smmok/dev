import java.util.UUID;

class PCString {
	public static void main(String args[]) {
		Q q = new Q();
		new Producer(q);
		new Consumer(q);
		System.out.println("Ctrl-C to exit");
	}
}

class Q {
	String s;
	boolean valueSet=false;

	synchronized String get() {
		while (!valueSet) {
			try {
				wait();
			} catch (InterruptedException e) {
				System.out.println("IE Caught");
			}
		}
		valueSet=false;
		System.out.println("Got: "+s);
		System.out.println("-----");
		notify();
		return s;
	}

	synchronized void set(String str) {
		while (valueSet) {
			try {
				wait();
			} catch(InterruptedException e) {
				System.out.println("IE Caught");
			}
		}
		this.s=str;
		valueSet=true;
		System.out.println("Set: "+str);
	    notify();
	}		
}

class Producer implements Runnable {
	Q q;

	Producer(Q q){
		this.q=q;
		new Thread(this,"Producer").start();
	}

	public void run() {
		String s;
		while(true) {
			s=generateString();
			q.set(s);
		}
	}

	public static String generateString() {
		String uuid = UUID.randomUUID().toString();
		return uuid;
	}
}

class Consumer implements Runnable {
	Q q;

	Consumer(Q q){
		this.q=q;
		new Thread(this,"Consumer").start();
	}

	public void run() {
		while(true) {
			q.get();
		}
	}
}

	
