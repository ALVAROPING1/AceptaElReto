FLAGS="-Werror -Wall -Wpedantic -g"
CC="gcc"
DIR="problems"

if [ "$1" != "file" ]; then
    FILE=$(compgen -G "$DIR/$1*")
else
    FILE=$2
fi

EXT="${FILE##*.}"

if [ "$EXT" = "cpp" ]; then
    FLAGS+=" -std=c++11"
    CC="g++"
else
    echo "#define inline" | cat - "$FILE" > program.c
    FILE="program.c"
fi

set -e
$CC "$FILE" $FLAGS
echo "Compiled Successfully"

./a.out
