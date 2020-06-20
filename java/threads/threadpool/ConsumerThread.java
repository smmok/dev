public class ConsumerThread implements Runnable {
  
    private String command;
    static strBuffer strbuffer = new strBuffer();
    
    public ConsumerThread(String s){
        this.command=s;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName()+" Start. Consumer = "+command);
        processCommand();
        System.out.println(Thread.currentThread().getName()+" End.");
    }

    private void processCommand() {
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println(strbuffer.get());
    }

    @Override
    public String toString(){
        return this.command;
    }
}



