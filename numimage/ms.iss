; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "�ҵĳ���"
#define MyAppVersion "1.5"
#define MyAppPublisher "�ҵĹ�˾"
#define MyAppURL "http://www.example.com/"
#define MyAppExeName "Groupwork.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (��Ҫ�����µ� GUID�����ڲ˵��е�� "����|���� GUID"��)
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
; ������ȡ��ע�ͣ����ڷǹ���װģʽ�����У���Ϊ��ǰ�û���װ����
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
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

