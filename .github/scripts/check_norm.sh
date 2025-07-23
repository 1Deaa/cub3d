#!/bin/bash

all_ok=true

for file in src/*.c; do
    result=$(norminette $file)

    if [[ "$result" == *"OK!"* ]]; then
        echo "$file: OK!"
    else
        echo "$file: ERROR!"
        all_ok=false
    fi
done

for file in libft/*.c; do
    result=$(norminette $file)

    if [[ "$result" == *"OK!"* ]]; then
        echo "$file: OK!"
    else
        echo "$file: ERROR!"
        all_ok=false
    fi
done

for file in include/*.h; do
    result=$(norminette $file)

    if [[ "$result" == *"OK!"* ]]; then
        echo "$file: OK!"
    else
        echo "$file: ERROR!"
        all_ok=false
    fi
done

if [ "$all_ok" = false ]; then
    echo "Some files did not pass Norminette checks!"
    exit 1
else
    echo "All files passed Norminette checks!"
    exit 0
fi