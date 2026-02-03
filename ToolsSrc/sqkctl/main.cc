#include "excel/config_generator.h"
#include <chrono>
#include <iostream>
#include <string>
#include <core/platform.h>

using namespace sqkctl;

void help() {
    std::cout << "Usague: sqkctl [cmd] [arg1] [arg2] ...\n"
              << "     excel:  \n"
              << "     version \n"
              << "  Examples: \n"
              << "  sqkctl excel ./Xlsx ./XlsxGen \n";
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        help();
        return 1;
    }

    const std::string cmd = argv[1];

    if (cmd == "excel") {
        if (argc < 4) {
            help();
            return 1;
        }
        std::string excelPath = argv[2];
        std::string outPath = argv[3];
        INFO("Excel path: " << excelPath);
        INFO("Out path: " << outPath);
        auto t1 = SquickGetTimeMS();
        Files::StringReplace(excelPath, "\\", "/");
        Files::StringReplace(excelPath, "//", "/");
        Files::StringReplace(outPath, "\\", "/");
        Files::StringReplace(outPath, "//", "/");
        ConfigGenerator fp(excelPath, outPath);
        fp.SetUTF8(false); // set it true to convert UTF8 to GBK which is to show Chinese words in Squick
        fp.LoadDataFromExcel();
        //fp.PrintData();
        fp.GenerateData();
        auto t2 = SquickGetTimeMS();
        INFO("Total costed time: " << (t2 - t1) << " ms");
    } else if (cmd == "version") {

    } else {
        help();
    }
    INFO("sqkctl exit 0");
    return 0;
}
