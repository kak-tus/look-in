open(ifl, 'template/ICQDefault.tmpl') || die();
open(ofl, '>template/ICQDefault.tmpl.out') || die();

while(<ifl>) {
  chomp();
  s/\"/\\\"/g;
  print(ofl $_."\\x0D\\x0A\" \\\n\"");
}

close(ifl);
close(ofl);