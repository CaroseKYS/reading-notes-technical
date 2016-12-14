import java.util.regex.*;
public class Test01{
  public static void main(String[] args){
    String str = "Subject: Test java Regular Expressions.";
    Pattern reg1 = Pattern.compile("^Subject: (.*)", Pattern.CASE_INSENSITIVE);
    Matcher m1 = reg1.matcher(str);
    if(m1.find()){
      String subject = m1.group(1);
      System.out.println(subject);
    }else{
      System.out.println("No matchers.");
    }
  }
}
