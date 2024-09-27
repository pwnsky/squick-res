#! /bin/bash
# Author: i0gan
# Email : l418894113@gmail.com
# Date  : 2022-11-27
# Github: https://github.com/pwnsky/squick
# Description: Generate configuration files
cd $(dirname $0)
excel_path="./Xlsx"
export_path="."

rm -rf $export_path/XlsxCode
rm -rf $export_path/XlsxXML

# 生成配置文件
mkdir -p $export_path/XlsxCode
mkdir -p $export_path/XlsxXML/Struct
mkdir -p $export_path/XlsxXML/Ini

./Tools/sqkctl excel $excel_path $export_path

if [[ "$1" == "server" ]];then
    echo "Copy to server"
    cp -a $export_path/XlsxCode/excel.h ../src/struct
    cp -a $export_path/XlsxCode/excel.lua ../src/lua/struct
fi