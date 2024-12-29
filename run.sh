FLAGS="-Werror -Wall -Wpedantic -g"
CC="gcc"

if [ "$1" != "file" ]; then
    FILE=$(compgen -G "problems/$1*")
else
    FILE=$2
fi

EXT="${FILE##*.}"

if [ "$EXT" = "cpp" ]; then
    FLAGS+=" -std=c++11"
    CC="g++"
fi

set -e
$CC "$FILE" $FLAGS
echo "Compiled Successfully"

./a.out
