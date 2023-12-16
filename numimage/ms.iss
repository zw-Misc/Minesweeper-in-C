; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！

#define MyAppName "我的程序"
#define MyAppVersion "1.5"
#define MyAppPublisher "我的公司"
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "Groupwork.exe"

[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (若要生成新的 GUID，可在菜单中点击 "工具|生成 GUID"。)
AppId={{CF7078A8-171C-40E8-A8E9-6A086E057B67}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
; 以下行取消注释，以在非管理安装模式下运行（仅为当前用户安装）。
;PrivilegesRequired=lowest
OutputDir=C:\Users\52869\Desktop\ms
OutputBaseFilename=mysetup
Compression=lzma
SolidCompression=yes
WizardStyle=modern

[Languages]
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "C:\Users\52869\Desktop\Groupwork\x64\Release\Groupwork.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\x64\Release\pthreadGC2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\x64\Release\pthreadVC2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\0.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\1.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\10.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\11.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\12.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\13.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\14.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\15.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\16.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\17.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\18.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\19.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\2.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\20.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\21.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\22.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\3.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\4.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\5.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\6.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\7.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\8.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\9.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\mhy.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\gameimage\minesweep.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\0.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\1.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\2.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\3.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\4.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\5.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\6.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\7.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\8.png"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Users\52869\Desktop\Groupwork\Groupwork\numimage\9.png"; DestDir: "{app}"; Flags: ignoreversion
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

