# Find path dependent on current directory ../leetcode-tasks
$targetPath = Resolve-Path ..\leetcode-tasks

# Folders to delete
$folderNames = @("build", ".cache", ".vscode")

$changeFilesCounter = 0
# Find and delete directories with name "build" & ".cache" recursively in folder ../leet-code
Get-ChildItem -Path $targetPath -Recurse -Directory |
    Where-Object { $folderNames -contains $_.Name } |
    ForEach-Object { # { <- could be only on that line. Do not move to new line
        try
        {
            Remove-Item $_.FullName -Recurse -Force -ErrorAction Stop
            Write-Host "Deleted: $($_.FullName)" -ForegroundColor Green
            $changeFilesCounter++
        }
        catch
        {
            Write-Host "Deletion failed: $($_.FullName) - error: $($_.Exception.Message)" -ForegroundColor Red
        }
    }

Write-Host "Deleted '$changeFilesCounter' directories." -ForegroundColor Green
Write-Host "Deletion completed." -ForegroundColor Green
