import java.util.regex.*;

public class Test_07_csv{
  public static void main(String[] args){
    String line = "Ten Thousand,10000, 2710 ,,\"10,000\",\"It's \"\"10 Grand\"\", baby\",10K";

    String regex = 
      "\\G(?:^|,)                   \n" + 
      "(?:                          \n" + 
      "  \"                         \n" + 
      "    ( (?:[^\"]|\"\")+ )      \n" +
      "  \"                         \n" + 
      "  |                          \n" + 
      "  ([^\",]*)                  \n" + 
      ")                            \n" ; 

    Matcher mMain = Pattern.compile(regex, Pattern.COMMENTS).matcher("");
    Matcher mQuote = Pattern.compile("\"\"").matcher("");

    mMain.reset(line);
    while( mMain.find() ){
      String field;
      if (mMain.start(2) >= 0) {
        field = mMain.group(2);
      }else{
        field = mQuote.reset(mMain.group(1)).replaceAll("\"");
      }

      System.out.printf("[%s] ", field);
    }

    System.out.println();
  }
}