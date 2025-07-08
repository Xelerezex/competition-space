# Задаём содержимое для файла settings.json
$settingsJsonContent =
@"
{
    "editor.formatOnSave": true, // Optional: to format on save
    // Cmake Extension setup:
    "cmake.useCMakePresets": "always",
    // "cmake.sourceDirectory": "/home/heather/workspace/personal_projects/opengl_space/app/static",
    // "cmake.buildDirectory": "/home/heather/workspace/build/opengl_space/gcc/vscode",
    "C_Cpp.intelliSenseEngine": "disabled",
    "C_Cpp.formatting": "clangFormat",
    // Use the .clang-format file in your project
    "clang-format.style": "file",
    "[c]": {
        "editor.defaultFormatter": "xaver.clang-format"
    },
    "[cpp]": {
        "editor.defaultFormatter": "xaver.clang-format"
    },
    // If you want to specify the path to clang-format (if it's not in PATH), use:
    // "C_Cpp.clang_format_path": "/path/to/clang-format"
    // ClangD setup:
    // "clangd.path": "/usr/lib/llvm-17/bin/clangd",
    "clangd.arguments": [
        "--enable-config",
        "--compile-commands-dir=${workspaceFolder}",
        "--clang-tidy",
        "-j=4"
    ],
    "clangd.fallbackFlags": [
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
