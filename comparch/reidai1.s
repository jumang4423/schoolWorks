         .data
A:       .word 47
B:       .word 314
C:       .word 0

         .text
main:    lw   $t0, A
         lw   $t1, B
         sub  $t2, $t0, $t1
         sw   $t2, C
exit: j  exit
