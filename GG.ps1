$qs=""
$a=$ARGS|%{
    if ($_ -match "#"){
        $_ -replace "#","%23"
    }
    else{
        $_
    }
}|%{ 
    if ($qs) { $qs += "+" }
    $qs += $_
}
$qs
start "https://www.google.co.jp/search?q=$qs"
