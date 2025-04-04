cd "`dirname $0`"

artifacts="artifacts"

if ! [ -d ./$artifacts ]; then
    mkdir $artifacts
fi

cd $artifacts
rm -rf ./*

source_files=(
    '../src/main.c'
    '../src/linked-list.c'
)

files=("${source_files[@]}")

args=""

if [ -f ./a.out ]; then
    rm a.out
    rm -rf *.dSYM
fi

for file in "${files[@]}"; do
    args+=$file' '
done

clang -g -Wall $args
