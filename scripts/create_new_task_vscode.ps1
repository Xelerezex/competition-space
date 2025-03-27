# Запрашиваем имя у пользователя:
$name = Read-Host "Enter task name: "
# ------------------------------------------------------------------------------

# Подключаем все файлы с наполнением:
. .\create_new_task_vscode_variables\cmake_lists_content.ps1
. .\create_new_task_vscode_variables\cmake_presets_content.ps1
. .\create_new_task_vscode_variables\main_cpp_content.ps1
. .\create_new_task_vscode_variables\readme_content.ps1
## Файлы относящиеся к корректной работе VS Code проекта:
. .\create_new_task_vscode_variables\vscode\c_cpp_properties_json_content.ps1
. .\create_new_task_vscode_variables\vscode\clang_format_content.ps1
. .\create_new_task_vscode_variables\vscode\clang_tidy_content.ps1
. .\create_new_task_vscode_variables\vscode\launch_json_content.ps1
. .\create_new_task_vscode_variables\vscode\settings_json_content.ps1
. .\create_new_task_vscode_variables\vscode\tasks_json_content.ps1
# ------------------------------------------------------------------------------

# Получаем родительскую директорию текущей папки:
$parentDir = Split-Path -Parent (Get-Location)
# Формируем путь к новой директории
$targetDir = Join-Path -Path $parentDir -ChildPath "leetcode-tasks/$name"
# Формируем путь к папке .vscode
$vsCodeDir = Join-Path -Path $parentDir -ChildPath "leetcode-tasks/$name/.vscode"
# Создаём директорию leetcode-tasks/$name (если её нет)
New-Item -ItemType Directory -Path $targetDir -Force | Out-Null
# Создаём директорию leetcode-tasks/.vscode (если её нет)
New-Item -ItemType Directory -Path $vsCodeDir -Force | Out-Null
# ------------------------------------------------------------------------------

# Формируем путь к файлу NAME.cpp:
$filePathCPP = Join-Path -Path $targetDir -ChildPath "$name.cpp"
# Формируем путь к файлу CMakeLists.txt:
$filePathCMakeLists = Join-Path -Path $targetDir -ChildPath "CMakeLists.txt"
# Формируем путь к файлу CMakePresets.json:
$filePathCMakePresets = Join-Path -Path $targetDir -ChildPath "CMakePresets.json"
# Формируем путь к файлу README.md:
$filePathReadMe = Join-Path -Path $targetDir -ChildPath "README.md"
# -------------------------------------
$filePathCCppPropertiesJson = Join-Path -Path $vsCodeDir -ChildPath "c_cpp_properties.json"
$filePathClangFormat = Join-Path -Path $vsCodeDir -ChildPath ".clang-format"
$filePathClangTidy = Join-Path -Path $vsCodeDir -ChildPath ".clang-tidy"
$filePathLaunchJson = Join-Path -Path $vsCodeDir -ChildPath "launch.json"
$filePathSettingsJson = Join-Path -Path $vsCodeDir -ChildPath "settings.json"
$filePathTasksJson = Join-Path -Path $vsCodeDir -ChildPath "tasks.json"

# Записываем содержимое в файлы:
$cppContent | Out-File -FilePath $filePathCPP -Encoding utf8
$cmakeListsContent | Out-File -FilePath $filePathCMakeLists -Encoding utf8
$cmakePresetsContent | Out-File -FilePath $filePathCMakePresets -Encoding utf8
$readMeContent | Out-File -FilePath $filePathReadMe -Encoding utf8
# -------------------------------------
$cCppPropertiesJsonContent | Out-File -FilePath $filePathCCppPropertiesJson -Encoding utf8
$clangFormatContent | Out-File -FilePath $filePathClangFormat -Encoding utf8
$clangTidyContent | Out-File -FilePath $filePathClangTidy -Encoding utf8
$launchJsonContent | Out-File -FilePath $filePathLaunchJson -Encoding utf8
$settingsJsonContent | Out-File -FilePath $filePathSettingsJson -Encoding utf8
$tasksJsonContent | Out-File -FilePath $filePathTasksJson -Encoding utf8

Write-Output "New task created!"
