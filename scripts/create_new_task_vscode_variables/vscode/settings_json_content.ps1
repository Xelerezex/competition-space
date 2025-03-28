# Задаём содержимое для файла settings.json
$settingsJsonContent =
@"
{
    // Cmake Extension setup:
    "cmake.useCMakePresets": "always",
    // "cmake.sourceDirectory": "/home/heather/workspace/personal_projects/opengl_space/app/static",
    // "cmake.buildDirectory": "/home/heather/workspace/build/opengl_space/gcc/vscode",

    // IntelliSense setup:
    "C_Cpp.intelliSenseEngine": "disabled",

    // ClangD setup:
    // "clangd.path": "/usr/lib/llvm-17/bin/clangd",
    "clangd.arguments": [
        "--enable-config",
        "--compile-commands-dir=`${workspaceFolder}",
        "--clang-tidy",
        "-j=4"
    ],
    "clangd.fallbackFlags":
    [
        "-std=c++20"
    ],
    "clangd.checkUpdates": true,
    "clangd.inactiveRegions.useBackgroundHighlight": true,
    "clangd.onConfigChanged": "restart",

    // "lldb.displayFormat": "auto",
    // "lldb.showDisassembly": "auto",
    // "lldb.dereferencePointers": true,
    // "lldb.consoleMode": "commands"
}
"@
