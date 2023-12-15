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
    $matches = preg_split(
        "/([0-9]+|[@#$%^&=*+\-\/])/",
        $line,
        -1,
        PREG_SPLIT_OFFSET_CAPTURE | PREG_SPLIT_DELIM_CAPTURE
    );
    $numRow= array();
    $symbolRow = array();
    foreach ($matches as $match) {
        if (is_numeric($match[0]))
            $numRow[$match[1]] = $match[0];
        else if (!str_starts_with($match[0], ".") and $match[0] != "" and $match[0] != "\n")
            $symbolRow[$match[1]] = $match[0];
    }
    array_push($nums, $numRow);
    array_push($symbols, $symbolRow);
    $lineCount++;
}
fclose($fp);

$sum = 0;
for ($lineIdx = 0; $lineIdx < $lineCount; $lineIdx++) {
    $prevSymbs = $symbols[$lineIdx-1] ?? [];
    $currSymbs = $symbols[$lineIdx];
    $nextSymbs = $symbols[$lineIdx+1] ?? [];
    $symbolArr = $prevSymbs + $currSymbs + $nextSymbs;

    foreach ($nums[$lineIdx] as $numIdx => $num)
        foreach ($symbolArr as $symbolIdx => $symbol) // Iterate through each symbol index
            if ($symbolIdx >= $numIdx-1 and $symbolIdx <= $numIdx + strlen($num)) { // Check if symbol is in bounds
                $sum += $num;
                break;
            }
}
echo "Sum: $sum\n"
?>