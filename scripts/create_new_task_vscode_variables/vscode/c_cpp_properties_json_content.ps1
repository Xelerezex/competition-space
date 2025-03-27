# Задаём содержимое для файла c_cpp_properties.json
$cCppPropertiesJsonContent =
@"
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "`${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:/mingw/mingw64/bin",
            "cStandard": "c11",
            "cppStandard": "c++20",
            "intelliSenseMode": "msvc-x64"
        }
    ],
    "version": 4
}
"@
