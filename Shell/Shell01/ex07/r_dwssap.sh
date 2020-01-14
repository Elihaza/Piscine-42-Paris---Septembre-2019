cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | cut -d ':' -f1 | rev | sed -n ''5', '15' ''p' | tr -d '\n' | sed 's/_/_, /g' | sed 's/, $/./' | tr -d '\n'
echo
