FLAGS="-Werror -Wall -Wpedantic -g -std=c++11"

g++ problems/$1\ *.cpp $FLAGS
X=$?

if [ $X != 0 ]; then
    exit $X
fi
echo "Compiled Successfully"

./a.out
