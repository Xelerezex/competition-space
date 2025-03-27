# Задаём содержимое для файла tasks.json
$tasksJsonContent =
@"
{
    "version": "2.0.0",
    "tasks":
    [
        {
            "label": "Скомпилировать C++",
            "type": "shell",
            "command": "g++",
            "args":
            [
                "-std=c++20",
                "-g",
                "`${file}",
                "-o",
                "`${fileDirname}\\`${fileBasenameNoExtension}.exe"
            ],
            "group":
            {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
"@
