FLAGS="-Werror -Wall -Wpedantic -g"
CC="gcc"

FILE=$(compgen -G "problems/$1*")
EXT="${FILE##*.}"

if [ "$EXT" = "cpp" ]; then
    FLAGS+=" -std=c++11"
    CC="g++"
fi

set -e
$CC "$FILE" $FLAGS
echo "Compiled Successfully"

./a.out
