<?php
    $fp = fopen("input.txt", "r");
    $sum = 0;
    while (($line = fgets($fp)) !== false) {
        $sum += 1;
    }
    echo $sum;
?>