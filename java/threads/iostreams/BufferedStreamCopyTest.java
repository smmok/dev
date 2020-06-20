/*

Java SE8 Programming: Date/Time API, I/O and File I/O (NIO.2), and concurrency

https://library.skillport.com/courseware/Content/ria/RIA_V3_1_1017/index_tablet.html?lang=en&AICC_URL=https%3A%2F%2Fpvsp80jdbe.skillport.com%3A443%2Fskillportbe%2Fscngc%2FResult.rbe&AICC_SID=10108008-99012773601911922219168-jl_sepr_a04_it_enus-A0-@0-SPCSF&CBTLAUNCH=jl_sepr_a04_it_enus_t60&COURSEINFO=skins/sp_pt0pc1ssl1db0&DYNAMIC_SKIN_URL=https://pvsp80jdbe.skillport.com:443/skillportbe/scngc/Cmd.be&tryRIA=true&use508=0&SIGNED_APPLET=true#

*/

package mok.swee.mean;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FileNotFoundException;
import java.io.IOException;

class myException extends Exception {
	public myException(String s) {
		super(s);
	}
}

class BufferedStreamCopyTest {

	public static void main(String[] args){

		try {
		    if (args.length != 2) {
			    throw new IllegalArgumentException("Usage: " + 
					"java one.two.three.BufferedStreamCopyTest " +
					"inputfile.txt outputfile.txt");
		    } 
			else
			{
				throw new myException("Copying [" + 
							args[0] + "] to [" + args[1] + "]");
			}
		} catch (IllegalArgumentException f) {
			System.out.println(f.getMessage());
			System.exit(-1);
		} catch (myException e) {
			System.out.println(e.getMessage());
		}

		try (BufferedReader bufInput
			= new BufferedReader(new FileReader(args[0]));
			BufferedWriter bufOutput
			= new BufferedWriter(new FileWriter(args[1])) ){

			String line = "";
			while ((line=bufInput.readLine()) != null) {
					bufOutput.write(line);
					bufOutput.newLine();
			}
		} catch (FileNotFoundException f) {
			System.out.println("File not found: " + f);
		} catch (IOException e) {
			System.out.println("Exception: " + e);
		}
	}
}

