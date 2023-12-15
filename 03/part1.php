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
            array_push($numRow, $match);
        else if (!str_starts_with($match[0], ".") and $match[0] != "" and $match[0] != "\n")
            array_push($symbolRow, $match);
    }
    array_push($nums, $numRow);
    array_push($symbols, $symbolRow);
    $lineCount++;
}
fclose($fp);

$sum = 0;
for ($lineIdx = 0; $lineIdx < $lineCount; $lineIdx++) {
    $prevNums = $nums[$lineIdx-1] ?? []; // Cool 'null coalescing' operator!
    $currentNums = $nums[$lineIdx];
    $nextNums = $nums[$lineIdx+1] ?? [];

    $prevSymbs = $symbols[$lineIdx-1] ?? [];
    $currentSymbs = $symbols[$lineIdx];
    $nextSymbs = $symbols[$lineIdx+1] ?? [];
    foreach ($currentNums as $numCell) {
        [$num, $numIdx] = $numCell;
        $numLen = strlen($num);

        $isPartNumber = false;
        foreach ($prevSymbs as $symbCell) { // Iterate through previous line's symbols
            [$symbol, $symbIdx] = $symbCell;
            if ($symbIdx >= $numIdx-1 and $symbIdx <= $numIdx + $numLen) { // Check if symbol is in bounds
                $isPartNumber = true;
                $sum += $num;
                break;
            }
        }
        foreach ($currentSymbs as $symbCell) { // Iterate through current line's symbols
            [$symbol, $symbIdx] = $symbCell;
            if ($symbIdx >= $numIdx-1 and $symbIdx <= $numIdx + $numLen) { // Check if symbol is in bounds
                $isPartNumber = true;
                $sum += $num;
                break;
            }
        }
        foreach ($nextSymbs as $symbCell) { // Iterate through next line's symbols
            [$symbol, $symbIdx] = $symbCell;
            if ($symbIdx >= $numIdx-1 and $symbIdx <= $numIdx + $numLen) { // Check if symbol is in bounds
                $isPartNumber = true;
                $sum += $num;
                break;
            }
        }
    }
}
echo "Sum: $sum\n"
?>