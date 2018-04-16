//
//        Author: Ibrar Yunus <Dated: 16/04/2018>
//
//        InsultProcessor: Generates insults of required number of words.
//        - overloaded constructor allows to read insults from custom file
//        - has a print facility to neatly print insults
//
//        ! Happy Swearing !
//


import java.io.*;
import java.util.ArrayList;
import java.util.Random;

public class InsultsProcessor {
    private ArrayList<String> insults = new ArrayList<String>();
    private String DEFAULT_PATH = "res/insults_list.swear";

    private void generateInsults(String path) throws IOException {
        File file = new File(path);
        FileReader filereader = new FileReader(file);
        BufferedReader br = new BufferedReader(filereader);
        StringBuffer sb = new StringBuffer();
        String line;
        while ((line = br.readLine())  != null) {
            insults.add(line);
        }
        filereader.close();
    }
    public InsultsProcessor() {
        System.out.println(this.getClass().getSimpleName() + " : initializing insults from default path");

        try {
            generateInsults(DEFAULT_PATH);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public InsultsProcessor(String path) {
        System.out.println(this.getClass().getSimpleName() + " : initializing insults from custom path: " + path);

        try {
            generateInsults(path);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void printInsults() {
        System.out.println(this.getClass().getSimpleName() + " : printing list of insults");

        int newline_counter = 4;

        System.out.println(insults.get(0));

        for(int i = 1; i < insults.size(); ++i) {
            System.out.print(insults.get(i) + " ");
            --newline_counter;
            if(newline_counter == 0) {
                System.out.print("\n");
                newline_counter = 4;
            }
        }
    }

    public String generateInsult( int number_of_words) {
        Random rn = new Random();
        StringBuilder sb = new StringBuilder();

        for( int i = 0; i < number_of_words; ++i) {
            int index = rn.nextInt(insults.size()) + 1;
            sb.append(insults.get(index));
            sb.append(' ');
        }

        return sb.toString();
    }

}
