# Получаем родительскую директорию текущей папки:
$parentDir = Split-Path -Parent (Get-Location)
# Формируем путь к новой директории
$leetcodeTasksDir = Join-Path -Path $parentDir -ChildPath "leetcode-tasks"
# Проверяем наличие директории leetcode-tasks
if (-Not (Test-Path $leetcodeTasksDir -PathType Container))
{
    Write-Host "There is no 'leetcode-tasks' directory in: $leetcodeTasksDir" -ForegroundColor Red
    exit
}
# ------------------------------------------------------------------------------

# Файлы относящиеся к корректной работе VS Code проекта:
. .\create_new_task_vscode_variables\vscode\c_cpp_properties_json_content.ps1
. .\create_new_task_vscode_variables\vscode\clang_format_content.ps1
. .\create_new_task_vscode_variables\vscode\clang_tidy_content.ps1
. .\create_new_task_vscode_variables\vscode\launch_json_content.ps1
. .\create_new_task_vscode_variables\vscode\settings_json_content.ps1
. .\create_new_task_vscode_variables\vscode\tasks_json_content.ps1
# ------------------------------------------------------------------------------

# Запрашиваем имя у пользователя:
$name = Read-Host "Enter task name"
# ------------------------------------------------------------------------------

# Формируем полный путь к искомой директории $name внутри "leetcode-tasks"
$targetPath = Join-Path -Path $leetcodeTasksDir -ChildPath $name
# Если директория NAME не существует, выводим сообщение и завершаем скрипт
if (-Not (Test-Path $targetPath -PathType Container))
{
    Write-Host "There is no directory '$name' не найдена в директории tasks." -ForegroundColor Red
    exit
}
# ------------------------------------------------------------------------------

# Формируем путь к папке VSCODE внутри директории NAME
$vscodePath = Join-Path -Path $targetPath -ChildPath ".vscode"
# Если папка VSCODE не существует, создаем её
if (-Not (Test-Path $vscodePath -PathType Container))
{
    # Создаем папку .vscode
    New-Item -ItemType Directory -Path $vscodePath | Out-Null

    # Забираем пути до файлов проекта
    # -----
    $filePathClangFormat = Join-Path -Path $targetPath -ChildPath ".clang-format"
    $filePathClangTidy = Join-Path -Path $targetPath -ChildPath ".clang-tidy"
    # -----
    $filePathCCppPropertiesJson = Join-Path -Path $vscodePath -ChildPath "c_cpp_properties.json"
    $filePathLaunchJson = Join-Path -Path $vscodePath -ChildPath "launch.json"
    $filePathSettingsJson = Join-Path -Path $vscodePath -ChildPath "settings.json"
    $filePathTasksJson = Join-Path -Path $vscodePath -ChildPath "tasks.json"
    # -----
    $cCppPropertiesJsonContent | Out-File -FilePath $filePathCCppPropertiesJson -Encoding utf8
    $clangFormatContent | Out-File -FilePath $filePathClangFormat -Encoding utf8
    $clangTidyContent | Out-File -FilePath $filePathClangTidy -Encoding utf8
    $launchJsonContent | Out-File -FilePath $filePathLaunchJson -Encoding utf8
    $settingsJsonContent | Out-File -FilePath $filePathSettingsJson -Encoding utf8
    $tasksJsonContent | Out-File -FilePath $filePathTasksJson -Encoding utf8

    Write-Host "Directory .vscode created successfully in '$name'." -ForegroundColor Green
}
else
{
    Write-Host "Directory .vscode exists in '$name'." -ForegroundColor Yellow
    $changeFilesCounter = 0

    # Проверяем существование всех нужных файлов проекта - если их нет, дописываем
    $filePathCCppPropertiesJson = Join-Path -Path $vscodePath -ChildPath "c_cpp_properties.json"
    if (-Not (Test-Path $filePathCCppPropertiesJson -PathType Leaf))
    {
        $cCppPropertiesJsonContent | Out-File -FilePath $filePathCCppPropertiesJson -Encoding utf8
        Write-Host "In .vscode added file '$filePathCCppPropertiesJson'." -ForegroundColor Green
        $changeFilesCounter++
    }
    $filePathClangFormat = Join-Path -Path $vscodePath -ChildPath ".clang-format"
    if (-Not (Test-Path $filePathClangFormat -PathType Leaf))
    {
        $clangFormatContent | Out-File -FilePath $filePathClangFormat -Encoding utf8
        Write-Host "In .vscode added file '$filePathClangFormat'." -ForegroundColor Green
        $changeFilesCounter++
    }
    $filePathClangTidy = Join-Path -Path $vscodePath -ChildPath ".clang-tidy"
    if (-Not (Test-Path $filePathClangTidy -PathType Leaf))
    {
        $clangTidyContent | Out-File -FilePath $filePathClangTidy -Encoding utf8
        Write-Host "In .vscode added file '$filePathClangTidy'." -ForegroundColor Green
        $changeFilesCounter++
    }
    $filePathLaunchJson = Join-Path -Path $vscodePath -ChildPath "launch.json"
    if (-Not (Test-Path $filePathLaunchJson -PathType Leaf))
    {
        $launchJsonContent | Out-File -FilePath $filePathLaunchJson -Encoding utf8
        Write-Host "In .vscode added file '$filePathLaunchJson'." -ForegroundColor Green
        $changeFilesCounter++
    }
    $filePathSettingsJson = Join-Path -Path $vscodePath -ChildPath "settings.json"
    if (-Not (Test-Path $filePathSettingsJson -PathType Leaf))
    {
        $settingsJsonContent | Out-File -FilePath $filePathSettingsJson -Encoding utf8
        Write-Host "In .vscode added file '$filePathSettingsJson'." -ForegroundColor Green
        $changeFilesCounter++
    }
    $filePathTasksJson = Join-Path -Path $vscodePath -ChildPath "tasks.json"
    if (-Not (Test-Path $filePathTasksJson -PathType Leaf))
    {
        $tasksJsonContent | Out-File -FilePath $filePathTasksJson -Encoding utf8
        Write-Host "In .vscode added file '$filePathTasksJson'." -ForegroundColor Green
        $changeFilesCounter++
    }
    Write-Host "Count of changed files: '$changeFilesCounter'." -ForegroundColor Green
}
