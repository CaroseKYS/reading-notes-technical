# 进入文件读取模式
undef $/;

# 读入命令行中指定的第一个文件
$text = <>;

$HostnameRegex = qr/[-a-z0-9]+(\.[-a-z0-9]+)*\.(com|edu|info)/i;

# 转意 &
$text =~ s/&/&amp;/g;

# 转意 <
$text =~ s/</&lt;/g;

# 转意 >
$text =~ s/>/&gt;/g;

# 划分段落
$text =~ s/^\s*$/<p>/mg;

# 将 e-mail 转换为链接形式
$text =~ s{
    \b
    (
      \w+[-.\w]*
      \@
      $HostnameRegex
    )
    \b
  }{<a href="$1">$1</a>}gix;

# 将 http url 转换为链接形式
$text =~ s{
    \b
    (
      https?://$HostnameRegex\b
      (
        /[-a-z0-9_:\@&?=+,.!/~*'%\$']*
      )?
    )
  }{<a href="$1">$1</a>}gix;

# 显示结果
print "$text\n";
