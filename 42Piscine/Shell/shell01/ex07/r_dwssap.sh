FT_LINE1=$FT_LINE1
FT_LINE2=$FT_LINE2
cat /etc/passwd | grep -v '#' | awk 'NR%2==0'| awk -F ":" '{print$1}' | rev | sort -r  |sed -n "${FT_LINE1},${FT_LINE2}p"| sed '$!s/$/,/' | tr '\n' ' '|sed 's/ *$//'|sed '$s/$/./'
