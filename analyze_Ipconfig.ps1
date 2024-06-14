chcp 437
$a=ipconfig
function isSectionHDR($_){
$_[0] -ne ' ' -and $_ -and $_[-1] -eq ':'
}
$h=@{}
$buf=@()
$aa=@()
$hdr_bak=""
$sections=@()
($a+"END:")|%{ 
    if(isSectionHDR $_){
        #"-------- $_ ----------" 
        $aa += @(,$buf)
        $sections+=$_
        $buf=@()
    } 
    else{
        if ($_) {
            $buf += $_
        }
    }
}
#$sections
$aa = $aa[1..($aa.Count-1)]
function chk($a, $s){
    do{
    $a|%{
        if ($_ -match $s){
            $false
            break
        }
    }
    $true
    }until(1)
}
0..($aa.Count-1)|%{
    if((chk $aa[$_] ": Media disconnected")){
        "------------- $($sections[$_]) -------------"
        $aa[$_]
    }
}|ogv -Title "analyze ipconfig"
$aa.Count
$sections.count
