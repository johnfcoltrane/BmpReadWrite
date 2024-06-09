line(){
    r=$1
    c=$2
    l=$3
    for ((i = 0; i < $l; i++)); do
        #echo Hello!
        #printf 'Hello! %d \n' $i
        printf '\e[%d;%dH*' $r $(($c+$i))
        sleep 0.1
        #printf '\e[%dm%d\e[m ' $i $i
    done
}
lineh(){
    r=$1
    j=$2
    l=$3
    for ((i = 0; i < $l; i++)); do
        #echo Hello!
        #printf 'Hello! %d \n' $i
        b=$(($r+$i))
        printf '\e[%d;%dH*' $b $j
        sleep 0.1
        #printf '\e[%dm%d\e[m ' $i $i
    done
}
clear
#line 10
oc=2 # offset-column
or=2 # offset-row
#ll=4
h=10
w=20
lineh $(($or+1)) $(($oc+1))      $h # row col len
lineh $(($or+1)) $(($oc+1+$w-1)) $h
line  $(($or+1))      $(($oc+1)) $w # row col len
line  $(($or+1+$h-1)) $(($oc+1)) $w # row col len

echo ""
