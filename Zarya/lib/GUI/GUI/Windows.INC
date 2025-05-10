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


Window :

mov  eax,0                     ; function 0 : define and draw window
    mov  bx,630                    ; [x start] *65536 + [x size]
    mov  cx,400                    ; [y start] *65536 + [y size]
    mov  edx,0x04ffffff            ; color of work area RRGGBB,8->color gl
    mov  esi,window_label          ; color of grab bar  RRGGBB,8->color gl
    mov  edi,0                     ; color of frames    RRGGBB
    int  0x40

window_label:

     db   'PROCESSES',0





