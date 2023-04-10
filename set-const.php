<?php

$Names = "Brick
Cast_Iron
Cobalt
Bronze
Concrete
Copper
Aluminium
Glass";

$Values ="5
10.8
12
17.5
13.5
16.6
23
36";

$Names  = explode("\r\n", $Names); 
$Values = explode("\r\n", $Values);
echo "enum subst {";
foreach ($Names as $key => $value) {
	echo strtoupper($value).", \n";
}
echo "\n};

";

foreach ($Names as $key => $value) {
	echo "Ex_Coeff[".strtoupper($value)."] = ".$Values[$key]."; \n";
}
echo "\n\n";
foreach ($Names as $key => $value) {
	echo "substance [".strtoupper($value)."] =   \"".$value."\"; \n";
}