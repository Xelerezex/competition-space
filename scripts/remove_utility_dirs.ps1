# Find path dependent on current directory ../leetcode-tasks
$targetPath = Resolve-Path ..\leetcode-tasks

# Folders to delete
$folderNames = @("build", ".cache")

# Find and delete directories with name "build" & ".cache" recursively in folder ../leet-code
Get-ChildItem -Path $targetPath -Recurse -Directory |
    Where-Object { $folderNames -contains $_.Name } |
    ForEach-Object {
        try {
            Remove-Item $_.FullName -Recurse -Force -ErrorAction Stop
            Write-Host "Deleted: $($_.FullName)"
        }
        catch {
            Write-Warning "Deletion failed: $($_.FullName) - error: $($_.Exception.Message)"
        }
    }

Write-Host "Deletion completed."
