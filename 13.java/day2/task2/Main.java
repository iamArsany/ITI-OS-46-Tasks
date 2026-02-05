public class Main {
  public static void main(String[] args) {
    String sentence="THis is java test , but java";
    String word="test";

    CountOccur test= new CountOccur(sentence,word);
    System.out.println(test.Count());


  }
}
