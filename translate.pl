#!G:/Perl/bin/perl

@f_nms = glob('*.cpp');
$st_tm = 0;

open(o_fl, ">translate.log") || die();

foreach $f_nm (@f_nms) {
  print(o_fl ";$f_nm\n");
  open(fl, $f_nm) || die();
  while (<fl>) {
    chomp;
    $s = $_;
    while ($s =~ m/Translate\(".*"\)/) {
      ($ts) = $s =~ m/Translate\("([^"]*)"\)/;
      $s =~ s/Translate\(".*"\)//;
      print(o_fl "[".$ts."]\n") if $ts ne '';
    }
  }
  close(fl);
}

open(fl, 'const.h');
print(o_fl ";const.h\n");
while (<fl>) {
  chomp;
  $s = $_;
  while ($s =~ m/".*"/) {
    ($ts) = $s =~ m/"([^"]*)"/;
    $s =~ s/".*"//;
    print(o_fl "[".$ts."]\n") if $ts ne '';
  }
}
close(fl);
