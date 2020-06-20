public class ProducerThread implements Runnable {
  
    private String command;
    private int strlen;
    private String output;

    static strBuffer strbuffer = new strBuffer();

    public ProducerThread(String s, int len){
        this.command=s;
        this.strlen = len;
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName()+" Start. Command = "+command);
        processCommand();
        System.out.println(Thread.currentThread().getName()+" End.");
    }

    private void processCommand() {
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        this.output="";
        for (int i=0; i<this.strlen; i++) {
          System.out.print(this.command + " # ");
          this.output += this.command+" & ";
        }
        System.out.println();
        s = this.output;  
    }

    @Override
    public String toString(){
        return this.command;
    }
}



