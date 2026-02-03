#pragma once

#include "../files.h"
#include "config_generator_data.h"
#include "common/color_cout.hpp"
#include <fstream>
#include <filesystem>

#if PLATFORM == PLATFORM_WIN
#include <direct.h>
#endif

namespace fs = std::filesystem;
namespace sqkctl {
class IGenerator {
  public:
    void SetPath(const std::string &excelPath, const std::string &outPath) {
        this->outPath = outPath;
        strXMLStructPath = outPath + "/XML/Struct";
        strXMLDataPath = outPath + "/XML/Data";
        strLuaDataPath = outPath + "/Lua/Data";
        strExcelDataPath = excelPath;
    }

    bool OpenFile(const std::string& file_path, std::ofstream& file, 
              std::ios::openmode open_mode = std::ios::out | std::ios::trunc) {
        try {
            fs::path full_file_path(file_path);
            fs::path dir_path = full_file_path.parent_path();
            if (!fs::exists(dir_path)) {
                fs::create_directories(dir_path);
            }
            
            file.open(full_file_path.string(), open_mode);
            if (!file.is_open()) {
                ERROR("Open file is failed: " << file_path);
                return false;
            }
            return true;
        }
        catch (const fs::filesystem_error& e) {
            ERROR("FIle system is error: " << e.what());
            return false;
        }
        catch (const std::exception& e) {
            ERROR("Unknown: " << e.what());
            return false;
        }
    }

    virtual bool Generate(const std::map<std::string, ClassData *> &classData) = 0;

    std::string strExcelDataPath;
    std::string strXMLStructPath;
    std::string strXMLDataPath;
    std::string strLuaDataPath;
    std::string outPath;
};

} // namespace sqkctl
