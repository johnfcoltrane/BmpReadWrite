# get original path from subst-drive (GetOriginalPath)
Param($d="t", [switch]$i=$false)
if ($i) {"Drive=$d"}
$p = ((cmd /c "subst|find /i ""$d`:""") -split " ")[2]
$p
