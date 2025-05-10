;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                                 ;;
;;  Windows.INC                                                       ;;
;;                                                                 ;;
;; Создает окно приложения                           ;;
;;                                                                 ;;
;;  Version 1    09ю052025 год                                     ;;
;;                                                                 ;;
;;  Юрин      ;;
;;                                                                 ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


Window:
mov  eax,0                     ; function 0 : define and draw window
    mov  bx,630                    ; [x start] *65536 + [x size]
    mov  cx,400                    ; [y start] *65536 + [y size]
    mov  edx,0x04ffffff            ; color of work area RRGGBB,8->color gl
    mov  esi,window_label2          ; color of grab bar  RRGGBB,8->color gl
    mov  edi,0                     ; color of frames    RRGGBB
    int  0x40
ret

window_label2:

     db   'PROCESSES',0

xm   equ 33


draw_window:


    mov  eax,12                    ; function 12:tell os about windowdraw
    mov  ebx,1                     ; 1, start of draw
    int  0x40

    mov  eax,12
    mov  ebx,1
    int  0x40

    mov  eax,14
    int  0x40

    mov  ebx,eax
    mov  ecx,eax

    shr  ebx,16
    and  ebx,0xffff
    and  ecx,0xffff

    shr  ebx,1
    shr  ecx,1

    sub  ebx,315
    sub  ecx,200

    shl  ebx,16
    shl  ecx,16
                                   ; DRAW WINDOW
   mov  eax,0                     ; function 0 : define and draw window
   mov  bx,630                    ; [x start] *65536 + [x size]
   mov  cx,400                    ; [y start] *65536 + [y size]
    mov  edx,0x04ffffff            ; color of work area RRGGBB,8->color gl
   mov  esi,window_label          ; color of grab bar  RRGGBB,8->color gl
   mov  edi,0                     ; color of frames    RRGGBB
   int  0x40          
    mov  ebx,20*65536+35           ; draw info text with function 4
    mov  ecx,0x000000
    mov  edx,text
    mov  esi,100
    mov  eax,4
    int  0x40

    mov  eax,8                      ; terminate buttons
    mov  ebx,530*65536+55
    mov  ecx,54*65536+9
    mov  edx,11
    mov  esi,0x10aabbcc
    mov  edi,0
   newb:
    int  0x40
    add  ecx,10*65536
    inc  edx
    cmp  edx,11+32
    jb   newb

    mov  eax,8                      ; terminate all
    mov  ebx,530*65536+55
    mov  ecx,380*65536+10
    mov  edx,61
    mov  esi,0x10aabbcc
    mov  edi,0
    int  0x40

    mov  eax,8                      ; previous
    mov  ebx,30*65536+96
    mov  ecx,380*65536+10
    mov  edx,51
    mov  esi,0xaabbcc
;    int  0x40

    mov  eax,8                      ; next
    mov  ebx,130*65536+96
    mov  ecx,380*65536+10
    mov  edx,52
    mov  esi,0xaabbcc
;    int  0x40

    mov  eax,8                      ; text enter
    mov  ebx,(237-6*xm)*65536+20
    mov  ecx,380*65536+10
    mov  edx,53
    mov  esi,0x10aabbcc
    mov  edi,0
    int  0x40

    mov  eax,8                      ; start application
    mov  ebx,(456-6*xm)*65536+63
    mov  ecx,380*65536+10
    mov  edx,54
    mov  esi,0x10aabbcc
    mov  edi,0
    int  0x40

    mov  eax,4
    mov  ebx,30*65536+382
    mov  ecx,0x000000
    mov  edx,tbts
    mov  esi,tbte-tbts
    int  0x40

    call draw_scroll

    call draw_process

    call print_text

    mov  eax,12                    ; function 12:tell os about windowdraw
    mov  ebx,2                     ; 2, end of draw
    int  0x40

    ret



