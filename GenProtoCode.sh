#!/bin/bash
# Author: i0gan
# Email : l418894113@gmail.com
# Date  : 2022-10-01
# Github: https://github.com/pwnsky/squick
# Description: Install development environment on linux
cd $(dirname $0)
source ../tools/common.sh
export LD_LIBRARY_PATH=`realpath  ../third_party/build/bin`:`realpath  ../third_party/build/lib`:`realpath ../third_party/build/protobuf`
echo $LD_LIBRARY_PATH

proto_bin='../third_party/build/bin/protoc'
proto_path="./Proto"
cpp_out_path="./ProtoCode/Cpp"
csharp_out_path='./ProtoCode/Csharp'
python_out_path='./ProtoCode/Python'
lua_out_path="./ProtoCode/Lua"

mkdir -p $csharp_out_path
mkdir -p $python_out_path
mkdir -p $lua_out_path
mkdir -p $cpp_out_path

# 生成Lua文件
cd Tools/proto
python3 gen_msgid.py
check_err
python3 proto_enum_to_lua.py
check_err
python3 proto_to_lua_str.py
check_err
cd ../..

proto_files=$proto_path/*.proto
for f in $proto_files
do
    echo $f
    $proto_bin --cpp_out=$cpp_out_path  --proto_path=$proto_path $f
    check_err
    $proto_bin --csharp_out=$csharp_out_path  --proto_path=$proto_path $f
    check_err
    $proto_bin --python_out=$python_out_path  --proto_path=$proto_path $f
    check_err
done

# remove nodes rpc files
rm $csharp_out_path/N*.cs

# copy for server
cp $cpp_out_path/* ../src/struct
check_err
mkdir -p ../pycli/proto
cp $python_out_path/* ../pycli/proto
check_err
cp $lua_out_path/enum_all.lua ../src/lua/proto/enum.lua

check_err
