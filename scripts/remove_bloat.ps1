$programs = @("WindowsMaps", "ZuneMusic", "ZuneVideo", "Microsoft3DViewer", "WindowsCamera", "Messaging", "BingWeather", "Getstarted", "OneNote", "OneConnect", "Print3D", "windowscommunicationsapps", "WindowsSoundRecorder", "YourPhone")

echo "See https://docs.microsoft.com/en-us/windows/application-management/apps-in-windows-10 for a list of all built-in applications. Edit this file to add or remove more. Double-check the list within this file to ensure the list is correct and you are OK with all the programs being removed completely from your system."

Read-Host -Prompt "Press enter to remove the programs or close this window to abort..."

foreach ($prog in $programs) {
  echo "Removing $prog"
  Get-AppxPackage *$prog* | Remove-AppxPackage
}

Read-Host -Prompt "Removal complete..."

