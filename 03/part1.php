<?php
$fp = fopen("input.txt", "r") or die("Unable to open file!");
$sum = 0;
$nums = array();
$symbols = array();
$lineCount = 0;
while ($line = fgets($fp)) {
    $numRow = array();
    $symbolRow = array();

    $idx = 0;
    $tups = preg_split(
        "/([0-9]+|[@#$%^&=*+\-\/])/",
        $line,
        -1,
        PREG_SPLIT_OFFSET_CAPTURE | PREG_SPLIT_DELIM_CAPTURE
    );

    print_r($tups);

    $lineCount++;
}
fclose($fp);
?>