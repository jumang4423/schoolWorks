         .data
A:       .word 325
B:       .word 25
C:       .word 242
FF:      .word 2021
S:       .word 0

         .text
main:    lw   $t0, A
         lw   $t1, B
         lw   $t2, C
         lw   $t3, FF
         add  $t4, $t0, $t1
         sub  $t5, $t4, $t2
         and  $t6, $t5, $t3
         sw   $t6, S
exit: j  exit