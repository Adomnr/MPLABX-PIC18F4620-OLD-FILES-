;====================================================================
; Main.asm file generated by New Project wizard
;
; Created:   Wed Jun 30 2021
; Processor: 80C31
; Compiler:  ASEM-51 (Proteus)
;====================================================================

$NOMOD51
$INCLUDE (8051.MCU)

;====================================================================
; DEFINITIONS
;====================================================================

;====================================================================
; VARIABLES
;====================================================================

;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================

      ; Reset Vector
      org   0000h
      jmp   Start

;====================================================================
; CODE SEGMENT
;====================================================================

      org   0100h
Start:	
      ; Write your code here
Loop:	
      jmp Loop

;====================================================================
      END
