FLAGS="-Werror -Wall -Wpedantic -g -std=c++11"

set -e
g++ problems/$1\ *.cpp $FLAGS
echo "Compiled Successfully"

./a.out
