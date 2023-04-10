<?php

$List="Brick,5
Cast_Iron,10.8
Cobalt,12
Bronze,17.5
Concrete,13.5
Copper,16.6
Aluminium,23
Glass,36
Ether,1650
Ethyl_alcohol,1100
Petrol,950
Glycerin,500
Mercury,180
Water,210
Air,3400";

$Names_Values = explode("\r\n", $List);

echo "enum subst {\n";
foreach ($Names_Values as $key => $value) {
	$v_array = explode(",", $value);
	echo strtoupper($v_array[0]).", \n";
}
echo "};

";

foreach ($Names_Values as $key => $value) {
	$v_array = explode(",", $value);
	echo "Ex_Coeff[".strtoupper($v_array[0])."] = ".$v_array[1]."; \n";
}
echo "\n\n";

foreach ($Names_Values as $key => $value) {
	$v_array = explode(",", $value);
	echo "substance [".strtoupper($v_array[0])."] =   \"".$v_array[0]."\"; \n";
}

