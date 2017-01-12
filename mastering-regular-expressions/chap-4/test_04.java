import java.util.regex.*;

public class test_04{
  public static void main(String [] agrs){
    String SubDomain = "(?i:[a-z0-9]|[a-z0-9][-a-z0-9]*[a-z0-9])";
    String TopDomains = "(?x-i:com\\b               \n" + 
                        "     |edu\\b               \n" +
                        "     |biz\\b               \n" + 
                        "     |in(?:t|fo)\\b        \n" + 
                        "     |mil\\b               \n" + 
                        "     |net\\b               \n" + 
                        "     |org\\b               \n" + 
                        "     |[a-z][a-z]\\b        \n" + //country codes                       
                        ")                          \n";
    
    String Hostname = "(?:" + SubDomain + "\\.)+" + TopDomains;
    
    String NOT_IN = ";\"'<>()\\[\\]{}\\s\\x7F-\\xFF";
    String NOT_END = "!.,?";
    String ANYWHERE = "[^" + NOT_IN + NOT_END + "]";
    String EMBEDDED = "[" + NOT_END + "]";
    String UrlPath = "/" + ANYWHERE + "*(" + EMBEDDED + "+" + ANYWHERE + "+)*";
    String Url = "(?x:                                                    \n" + 
                 "  \\b                                                   \n" + 
                 "  ## 匹配 hostname                                      \n" + 
                 "  (                                                     \n" + 
                 "    (?: ftp | http s?): // [-\\w]+(\\.\\w[-\\w]*)+      \n" + 
                 "    |                                                   \n" + 
                 "    " + Hostname + "                                    \n" +
                 "  )                                                     \n" + 
                 "    # 可能出现的端口号                                  \n" +
                 "  (?: :\\d+ )?                                          \n" +
                 "                                                        \n" + 
                 "   # 下面的部分可能出现， 以/开头                       \n" +
                 "  (?:  )" + UrlPath + ")?                               \n" +
                 ")";
    
    System.out.println(Url);
    Pattern UrlRegex = Pattern.compile(TopDomains);
  }
}