import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ProducerConsumerThreadPool {

    static private String workString = "SWEEMOK";

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(3);
        for (int i = 0; i < 7 ; i++) {
            Runnable worker = new ProducerThread(workString,i);
            executor.execute(worker);
            Runnable consumer = new ConsumerThread(workString);
            executor.execute(consumer);
          }
        executor.shutdown();
        while (!executor.isTerminated()) {
        }
        System.out.println("Finished all threads");
    }
}

