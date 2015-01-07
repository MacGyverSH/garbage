<?php

$f = fopen("part.nc","r");
$fo = fopen("logo.nc","w");

while (($line = fgets($f, 4096)) !== false) {
	
	$parts = explode(" ", trim($line));
	
	foreach($parts as $k=>$p){
		$parts[$k] = substr($p, 0, 6);
	}
	
	fwrite($fo, implode(" ",$parts)."\n");
}

fclose($f);
fclose($fo);