import java.io.*;
import java.util.Scanner;

class ShrinkFile {

	public static void main(String args[]) throws IOException {
      
      int skipLines=0;

		if (args.length != 1) {
			System.out.println("Usage: ShrinkFile NumOfLinesToSkip");
			System.exit(0);
		} else {
			skipLines = Integer.parseInt(args[0]);
		}

		createDummyFile("Dummy.txt",100);

		FileInputStream fstream = new FileInputStream("Dummy.txt");
	   BufferedReader br = new BufferedReader(new InputStreamReader(fstream));
		String strLine;
		int counter=0;

		while ((strLine = br.readLine()) != null)
		{
			if (counter>skipLines) {
				counter=0;	
				System.out.println(strLine);
			} else {
				counter++;
			}
		}
		System.out.println("*****End*****");
	}



	private static void createDummyFile(String filename, int numLines) {

		String str = "";

		try (Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(filename),"UTF-8"))) {
			for (int i=0; i<numLines; i++) {
				str = "";
				str = String.valueOf(i);
				str = str + " Testing";
				str = str + "\n";
				writer.write(str);
			}
		} catch (IOException e) {
			System.out.println("Problem writing to file.");
		}
	}
}
	
