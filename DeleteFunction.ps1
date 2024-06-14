#DeleteFunction.ps1
Param($fnc)
#try{
#gi function:isSectionHDR
#$fnc="isSectionHDR"
if (test-Path function:$fnc){
    rm function:$fnc
    "削除しました。[function;$fnc]"
}
else{
    "[function:$fnc]は存在しません。"
}
#catch{
#$_
#}
