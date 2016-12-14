# 进入文件读取模式
undef $/;

# 读入命令行中指定的第一个文件
$text = <>;

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
      [-a-z0-9]+(\.[-a-z0-9]+)*\.(?:com|edu|info)
    )
    \b
  }{<a href="$1">$1</a>}gix;

# 将 http url 转换为链接形式
$text =~ s{
    \b
    (
      https?://[-a-z0-9]+(\.[-a-z0-9]+)*\.(com|edu|info)\b
      (
        /[-a-z0-9_:\@&?=+,.!/~*'%\$']*
      )?
    )
  }{<a href="$1">$1</a>}gix;

# 显示结果
print "$text\n";
