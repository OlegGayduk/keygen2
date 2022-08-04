.386
.model flat, stdcall
option casemap: none

include G:/Fhantom/lib.inc

include C:/masm32/include/gdi32.inc
includelib C:/masm32/lib/gdi32.lib
 
includelib C:/masm32/lib/user32.lib
includelib C:/masm32/lib/kernel32.lib

.data

hInstance dd ?

hWndEdit HWND ?
hWndEdit2 HWND ?
hWndBtn HWND ?

res db ?

nick dd ?

txtbuff db 255 dup(?)    

ClassMainName db 'test',0
WinMainName db "KeyGen for FaNtOm's Crackme #4",0 ; 

labelType db "static",0
edit db "edit",0
btn db "button",0

labelName db "Enter your name here: ",0
labelPass db "Your key: ",0
labelAuth db "cODEd bY [UltraLazer]",0

genText db "Generate",0
extBtnText db "Exit",0
abtBtnText db "About",0

abtMsgTitle db "About",0
abtMsgText db "KeyGen for FaNtOm's Crackme #4 made by UltraLazer",0

error db "Enter your name please!",0

hfont dd ?

lf LOGFONT <14,5,0,0,0,0,0,0,0,0,0,0,0,'Sans-serif'>                

.const

labelIdName equ 1
labelIdPass equ 2
labelIdAuth equ 3

editName equ 4
editPass equ 5

genBtnId equ 6
extBtnId equ 7
abtBtnId equ 8

.code
start:

invoke GetModuleHandle, 0
mov hInstance, eax
invoke WinMain, hInstance,0, 0, 1
invoke ExitProcess, 0

WinMain proc hInst:HINSTANCE, hPrevInst:HINSTANCE, CmdLine:LPSTR, CmdShow:DWORD
LOCAL wc:WNDCLASSEX
LOCAL msg:MSG
LOCAL hWnd:HWND

    mov wc.cbSize, SIZEOF WNDCLASSEX
    mov wc.style, CS_HREDRAW or CS_VREDRAW
    mov wc.lpfnWndProc, OFFSET WndProc
    mov wc.cbWndExtra, 0
    mov wc.cbClsExtra,DLGWINDOWEXTRA
    mov wc.hbrBackground,COLOR_BTNFACE+1
    mov wc.lpszMenuName, 0
    mov wc.lpszClassName, OFFSET ClassMainName
    invoke LoadIcon, 0, IDI_APPLICATION
    mov wc.hIcon, eax
    mov wc.hIconSm, eax
    invoke LoadCursor, 0, IDC_ARROW
    mov wc.hCursor, eax
    invoke RegisterClassEx, addr wc

    INVOKE CreateWindowEx,0,addr ClassMainName,addr WinMainName,\
    WS_OVERLAPPEDWINDOW-WS_SIZEBOX-WS_MAXIMIZEBOX,CW_USEDEFAULT,\
    CW_USEDEFAULT,430,165,0,0,\
    hInst,0

    mov hWnd, eax

    invoke ShowWindow, hWnd,1
    invoke UpdateWindow, hWnd

    .while TRUE
        invoke GetMessage, addr msg, 0, 0, 0
        .break .if(!eax)
        invoke TranslateMessage, addr msg
        invoke DispatchMessage, addr msg
    .endw
    mov eax, msg.wParam
    ret
WinMain endp

WndProc proc hWnd:DWORD, uMsg:DWORD, wParam:DWORD, lParam:DWORD

.IF uMsg==WM_CREATE   

    invoke CreateFontIndirectA,addr lf
    mov hfont,eax

    invoke CreateWindowEx, 0,addr labelType,addr labelName,WS_CHILD or WS_VISIBLE ,12, 5, 200, 15, hWnd, labelIdName,hInstance, 0 
    invoke SendMessageA,eax,WM_SETFONT,hfont,1
    
    invoke CreateWindowEx,WS_EX_CLIENTEDGE, addr edit,0,WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_AUTOHSCROLL,12,25,300,25,hWnd,editName,hInstance,0
    mov hWndEdit,eax
    invoke SendMessageA,eax,WM_SETFONT,hfont,1
    invoke SetFocus, eax

    invoke CreateWindowEx, 0,addr labelType,addr labelPass,WS_CHILD or WS_VISIBLE ,12, 55, 200, 20, hWnd, labelIdPass,hInstance, 0 
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

    invoke CreateWindowEx,WS_EX_CLIENTEDGE, addr edit,0,WS_CHILD or WS_VISIBLE or WS_BORDER or ES_LEFT or ES_READONLY or ES_AUTOHSCROLL,12,75,300,25,hWnd,editPass,hInstance,0
    mov hWndEdit2,eax
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

    invoke CreateWindowEx, 0,addr labelType,addr labelAuth,WS_CHILD or WS_VISIBLE ,12, 110, 200, 20, hWnd, labelIdAuth,hInstance, 0 
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

    invoke CreateWindowEx,WS_EX_LTRREADING,addr btn,addr genText,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,330,15,80,25,hWnd,genBtnId,hInstance,0
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

    invoke CreateWindowEx,WS_EX_LTRREADING,addr btn,addr extBtnText,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,330,50,80,25,hWnd,extBtnId,hInstance,0
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

    invoke CreateWindowEx,WS_EX_LTRREADING,addr btn,addr abtBtnText,WS_CHILD or WS_VISIBLE or BS_PUSHBUTTON,330,100,80,25,hWnd,abtBtnId,hInstance,0
    invoke SendMessageA,eax,WM_SETFONT,hfont,1

.ELSEIF uMsg==WM_COMMAND
    mov eax,wParam
    .IF lParam==0
    .ELSE
    .IF ax==genBtnId
        shr eax,16
	.IF ax==BN_CLICKED
    
        invoke GetWindowTextLength,hWndEdit
    
        .if al > 0

            invoke GetDlgItemText, hWnd, editName, addr nick, 30
            
            call generate
            
            invoke SetWindowText,hWndEdit2,addr res

            mov txtbuff,0

            mov res,0
            mov nick,0
            
        .else

            invoke SetWindowText,hWndEdit2,addr error
        .endif
           
     .ENDIF
     .ELSEIF ax==extBtnId
        shr eax,16
        .IF ax==BN_CLICKED
            invoke PostQuitMessage, 0
        .endif
      .ELSEIF ax==abtBtnId
        shr eax,16
        .IF ax==BN_CLICKED
            invoke MessageBox,0,offset abtMsgText,addr abtMsgTitle,MB_OK
     .ENDIF
     .ENDIF
     .ENDIF
.ELSEIF uMsg==WM_DESTROY
invoke PostQuitMessage, 0
.ELSE
invoke DefWindowProc, hWnd, uMsg, wParam, lParam
.ENDIF
ret
WndProc endp

generate:
	
    mov esi,eax

    xor eax,eax 
    xor ecx,ecx
    xor edx,edx
    xor ebx,ebx
    
    mov bl,26
    
    ;mov txtbuff,0
    
    cycle:
    mov al,byte ptr nick[ecx]
    add al,cl
    xor al,cl
    div bl
    shr ax,8
    add al,65
    mov res[ecx],al
    inc ecx 
    cmp ecx,esi
    jnz cycle
    
    mov res[ecx],0

    ret
    
end start