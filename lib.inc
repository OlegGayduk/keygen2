.data
HWND typedef DWORD
HINSTANCE typedef DWORD
LPSTR typedef DWORD

WNDCLASSEXA STRUCT
  cbSize            DWORD      ?
  style             DWORD      ?
  lpfnWndProc       DWORD      ?
  cbClsExtra        DWORD      ?
  cbWndExtra        DWORD      ?
  hInstance         DWORD      ?
  hIcon             DWORD      ?
  hCursor           DWORD      ?
  hbrBackground     DWORD      ?
  lpszMenuName      DWORD      ?
  lpszClassName     DWORD      ?
  hIconSm           DWORD      ?
WNDCLASSEXA ENDS

WNDCLASSEXW STRUCT
  cbSize            DWORD      ?
  style             DWORD      ?
  lpfnWndProc       DWORD      ?
  cbClsExtra        DWORD      ?
  cbWndExtra        DWORD      ?
  hInstance         DWORD      ?
  hIcon             DWORD      ?
  hCursor           DWORD      ?
  hbrBackground     DWORD      ?
  lpszMenuName      DWORD      ?
  lpszClassName     DWORD      ?
  hIconSm           DWORD      ?
WNDCLASSEXW ENDS

IFDEF __UNICODE__
    WNDCLASSEX  equ  <WNDCLASSEXW>
ELSE
    WNDCLASSEX  equ  <WNDCLASSEXA>
ENDIF

MSG STRUCT
  hwnd      DWORD      ?
  message   DWORD      ?
  wParam    DWORD      ?
  lParam    DWORD      ?
  time      DWORD      ?
  ;pt        POINT      <>
MSG ENDS

hinst DWORD  ?

LoadIconA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadIcon equ <LoadIconA>
ENDIF

LoadIconW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LoadIcon equ <LoadIconW>
ENDIF

LoadCursorA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  LoadCursor equ <LoadCursorA>
ENDIF

LoadCursorFromFileA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  LoadCursorFromFile equ <LoadCursorFromFileA>
ENDIF

LoadCursorFromFileW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  LoadCursorFromFile equ <LoadCursorFromFileW>
ENDIF

LoadCursorW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  LoadCursor equ <LoadCursorW>
ENDIF

RegisterClassExA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  RegisterClassEx equ <RegisterClassExA>
ENDIF

RegisterClassExW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  RegisterClassEx equ <RegisterClassExW>
ENDIF

CreateWindowExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExA>
ENDIF

CreateWindowExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateWindowEx equ <CreateWindowExW>
ENDIF

ShowWindow PROTO STDCALL :DWORD,:DWORD
UpdateWindow PROTO STDCALL :DWORD

GetMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetMessage equ <GetMessageA>
ENDIF

GetMessageExtraInfo PROTO STDCALL
GetMessagePos PROTO STDCALL
GetMessageTime PROTO STDCALL

GetMessageW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetMessage equ <GetMessageW>
ENDIF

TranslateMessage PROTO STDCALL :DWORD

DispatchMessageA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  DispatchMessage equ <DispatchMessageA>
ENDIF

DispatchMessageW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  DispatchMessage equ <DispatchMessageW>
ENDIF

SetFocus PROTO STDCALL :DWORD

GetWindowTextLengthA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetWindowTextLength equ <GetWindowTextLengthA>
ENDIF

GetWindowTextLengthW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetWindowTextLength equ <GetWindowTextLengthW>
ENDIF

GetDlgItemTextA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  GetDlgItemText equ <GetDlgItemTextA>
ENDIF

GetDlgItemTextW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  GetDlgItemText equ <GetDlgItemTextW>
ENDIF

SetWindowTextA PROTO STDCALL :DWORD,:DWORD
IFNDEF __UNICODE__
  SetWindowText equ <SetWindowTextA>
ENDIF

SetWindowTextW PROTO STDCALL :DWORD,:DWORD
IFDEF __UNICODE__
  SetWindowText equ <SetWindowTextW>
ENDIF

PostQuitMessage PROTO STDCALL :DWORD

DefWindowProcA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  DefWindowProc equ <DefWindowProcA>
ENDIF

DefWindowProcW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  DefWindowProc equ <DefWindowProcW>
ENDIF

GetModuleHandleA PROTO STDCALL :DWORD
IFNDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleA>
ENDIF

GetModuleHandleW PROTO STDCALL :DWORD
IFDEF __UNICODE__
  GetModuleHandle equ <GetModuleHandleW>
ENDIF

ExitProcess PROTO STDCALL :DWORD

;hwndEdit HWND ?
;hwndEdit2 HWND ?
;hwndBtn HWND ?
;hwndLabel DD ?
;hwndLabe2 DD ?

WinMain PROTO STDCALL :DWORD, :DWORD, :DWORD, :DWORD
WndProc PROTO STDCALL :DWORD, :DWORD, :DWORD, :DWORD

SendMessageA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  SendMessage equ <SendMessageA>
ENDIF

MessageBoxA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MessageBox equ <MessageBoxA>
ENDIF

MessageBoxExA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  MessageBoxEx equ <MessageBoxExA>
ENDIF

MessageBoxExW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  MessageBoxEx equ <MessageBoxExW>
ENDIF

CreateDialogParamA PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFNDEF __UNICODE__
  CreateDialogParam equ <CreateDialogParamA>
ENDIF

CreateDialogParamW PROTO STDCALL :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
IFDEF __UNICODE__
  CreateDialogParam equ <CreateDialogParamW>
ENDIF

GetCommandLineA PROTO STDCALL
IFNDEF __UNICODE__
  GetCommandLine equ <GetCommandLineA>
ENDIF

GetCommandLineW PROTO STDCALL
IFDEF __UNICODE__
  GetCommandLine equ <GetCommandLineW>
ENDIF

LF_FACESIZE                          equ 32

LOGFONTA STRUCT
  lfHeight          DWORD      ?
  lfWidth           DWORD      ?
  lfEscapement      DWORD      ?
  lfOrientation     DWORD      ?
  lfWeight          DWORD      ?
  lfItalic          BYTE      ?
  lfUnderline       BYTE      ?
  lfStrikeOut       BYTE      ?
  lfCharSet         BYTE      ?
  lfOutPrecision    BYTE      ?
  lfClipPrecision   BYTE      ?
  lfQuality         BYTE      ?
  lfPitchAndFamily  BYTE      ?
  lfFaceName        BYTE LF_FACESIZE dup(?)
LOGFONTA ENDS

LOGFONTW STRUCT
  lfHeight          DWORD      ?
  lfWidth           DWORD      ?
  lfEscapement      DWORD      ?
  lfOrientation     DWORD      ?
  lfWeight          DWORD      ?
  lfItalic          BYTE      ?
  lfUnderline       BYTE      ?
  lfStrikeOut       BYTE      ?
  lfCharSet         BYTE      ?
  lfOutPrecision    BYTE      ?
  lfClipPrecision   BYTE      ?
  lfQuality         BYTE      ?
  lfPitchAndFamily  BYTE      ?
  lfFaceName        WORD LF_FACESIZE dup(?)
LOGFONTW ENDS

IFDEF __UNICODE__
    LOGFONT  equ  <LOGFONTW>
ELSE
    LOGFONT  equ  <LOGFONTA>
ENDIF


;hFont HFONT ?

HFONT                       typedef DWORD

;hfont dd 1

FW_NORMAL                            equ 400
RUSSIAN_CHARSET                      equ 204
OUT_DEFAULT_PRECIS                   equ 0
CLIP_DEFAULT_PRECIS                  equ 0
DEFAULT_QUALITY                      equ 0
FF_MODERN                            equ 48
FIXED_PITCH                          equ 1

META_CREATEFONTINDIRECT              equ 2FBh


;C STRUCT

WM_LBUTTONDBLCLK                     equ 203h
WM_CLOSE                             equ 10h

SW_SHOWDEFAULT                       equ 10
SW_SHOWNORMAL                        equ 1

IDI_ASTERISK                         equ 32516
IDC_HAND                          equ 32649
CS_BYTEALIGNWINDOW                   equ 2000h
CS_SAVEBITS                          equ 800h
CS_DBLCLKS                           equ 8h

WS_EX_RTLREADING                     equ 00002000h
WS_EX_LTRREADING                     equ 00000000h

TRUE                                 equ 1

IDI_APPLICATION                      equ 32512
IDC_ARROW                            equ 32512
CW_USEDEFAULT                        equ 80000000h

WM_CREATE                            equ 1h
WM_COMMAND                           equ 111h
BN_CLICKED                           equ 0
WM_DESTROY                           equ 2h

WS_VISIBLE                           equ 10000000h

WS_THICKFRAME                        equ 40000h

WS_OVERLAPPED                        equ 0h
WS_CAPTION                           equ 0C00000h
WS_SYSMENU                           equ 80000h
WS_CHILD                             equ 40000000h
WS_EX_CLIENTEDGE                     equ 00000200h
WS_DISABLED                          equ 8000000h

;MSGF_MESSAGEBOX     equ 1
MB_OK                                equ 0h

WS_SIZEBOX                           equ WS_THICKFRAME

WS_MAXIMIZEBOX                       equ 10000h
WS_MINIMIZEBOX                       equ 20000h
WS_BORDER                            equ 800000h
BS_DEFPUSHBUTTON                     equ 1h

ES_READONLY                          equ 800h
ES_LEFT                              equ 0h
ES_AUTOHSCROLL                       equ 80h

CS_HREDRAW                           equ 2h
CS_VREDRAW                           equ 1h
DLGWINDOWEXTRA                       equ 30
COLOR_BTNFACE                        equ 15

WS_OVERLAPPEDWINDOW                  equ WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX

WM_SETFONT                           equ 30h

BS_PUSHBUTTON                        equ 0h