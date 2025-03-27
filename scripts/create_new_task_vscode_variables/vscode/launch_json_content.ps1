# Задаём содержимое для файла launch.json
$launchJsonContent =
@"
{
  "version": "0.2.0",
  "configurations":
  [
      {
          "name": "Start C++ debug",
          "type": "cppdbg",
          "request": "launch",
          "program": "`${fileDirname}/build/`${fileBasenameNoExtension}.exe",
          "cwd": "`${workspaceFolder}",
          "MIMode": "gdb",
          "setupCommands": [
              {
                  "description": "Enable pretty-printing for gdb",
                  "text": "-enable-pretty-printing",
                  "ignoreFailures": false
              }
        ]
      }
  ]
}
"@
