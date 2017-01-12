# $text = "http://www.cctaa-wx.cn/course/sp1672005.html";
$text = "www.cctaa-wx.cn:80/course/sp1672005.html.";

if ($text =~ m{
    \b
    # 匹配开头部分 proto://hostname 或 hostname
    (
      # 有标准协议开头的URL
      (?:ftp|https?)://[-\w]+(?:\.\w[-\w]*)+
      |
      # 或者直接用精确的子表达式找到hostname
      (?: [a-z0-9](?:[-a-z0-9]*[a-z0-9])?\.)+
      # .com 之类的内容
      (?:
        com\b |
        edu\b |
        biz\b |
        gov\b |
        in(?:t|fo)?\b | # .int 或 .info
        mil\b |
        net\b |
        org\b |
        [a-z][a-z]\b
      )
    )
    # 可能出现的端口号
    (?::(\d+))?

    # 可能出现的路径
    (
      /
      [^.!,?;"'<>\[\]{}\s\x7F-\xFF]*
      (?:
        [.!,?]+ [^.!,?;"'<>\[\]{}\s\x7F-\xFF]+
      )*
    )?
  }x) {
  print "$1\n";
  print "$2\n";
  print "$3\n";
}