cat /etc/passwd | grep -v '^#' | sed -n 'n;p' | rev | grep -o '[^:]*$' | sort -r | paste -sd ',' - | sed 's/,/, /g' | sed 's/$/./' | tr '\n' ' '
