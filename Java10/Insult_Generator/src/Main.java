//
//        Author: Ibrar Yunus <Dated: 16/04/2018>
//
//        Test Utility for InsultProcessor class
//
//        ! Happy Swearing !
//

public class Main {

    public static void main(String[] args) {
        System.out.println("[*] Testing Insults Generator");
        InsultsProcessor ip = new InsultsProcessor();

        System.out.println("-- Testing insults!");
        for (int i = 2; i < 5; ++i) {
            System.out.println("==============");
            System.out.println("Generated insult of word length: " + i);
            System.out.println(ip.generateInsult(i));
        }
    }
}
