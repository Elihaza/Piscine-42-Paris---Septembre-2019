find . -name "*.sh" | sed 's/.\{3\}$//' | rev | cut -d '/' -f1 | rev
