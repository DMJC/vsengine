#!/usr/bin/perl
# adds a light and a star referring to that light
use POSIX qw(floor);

@color_table = ( [ 1,.3,.1 ], [.5,.5,1] ,[1,.8,5],[1,1,.7],[.6,.6,1],[1,.9,1],[1,1,1],[1,.2,.2],[.5,.5,1],[1,.8,.5],[1,1,.7],[1,.9,1],[1,1,1],[.6,.6,1],[1,.6,.6]);
$state = 0;
$sysname = $ARGV[0];
print STDERR $sysname;
$sysname =~ s/system$//;
$sysname =~ s{[/.]}{}g;
$red = $green = $blue = 0;
$sr = $sg = $sb = 0;
@colors = (\$red, \$green, \$blue);

#      srand(time());
while($foo=<>) {
  @tokens = split //,$foo;
      print $foo;
  while(@tokens) {
    $tok = shift @tokens;
    if($state==0 && $tok eq "<") {
      $state=1;
    } 
    elsif($state==1 && $tok eq ">") {
      $state=-1;

      ($red,$green,$blue) = @{$color_table[floor(rand(1)*@color_table)]};
      $sr = sqrt ($red);
      $sg = sqrt ($green);      $sb = sqrt ($blue);
if(0) {
      ${$colors[floor(rand(3))]} = 1;
      for $colorref (@colors) {
        if($$colorref==0) {
          $$colorref = rand(1);
        } 
      }
}
      print STDERR "aardvark ($red,$green,$blue)\n";
      print <<FOO
<Light>
<ambient red=".3" green=".3" blue=".3"/>
<diffuse red="$sr" green="$sg" blue="$sb"/>
<specular red="$red" green="$green" blue="$blue"/>
</Light>

FOO
;
      print <<BAR
<Planet name="$sysname" file="sol/sun.png" radius="10000000" x="14594814.00
0000" y="14594814.000000" z="-14594814.000000"  Red="$red" Green="$green" Blue="$blue" ReflectNoLight="true" light="0"/>

BAR
;
    }
  }
}

