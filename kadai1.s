            .data
A:      .word 43     # A[0] = 43
        .word 22     # A[1] = 22
        .word 11
        .word 53
        .word 21
        .word 67
        .word 93
        .word 87
        .word 36     # A[8] = 36
ADDRESS_A:  .word 20480   #00005000 of decimal
FOUR:       .word 4
N:      .word 9    # The length of Array
S:      .word 0
ONE:    .word 1

            .text
main:   lw   $t1, ADDRESS_A
        lw   $t2, FOUR
        lw   $t4, N
	lw   $t5, ONE
        lw   $t6, S
	or   $t0, $0, $5

loop:   beq  $t4, $t0, loopend
        add  $t0, $t0, $t5      # i++
	lw   $t7, 0($t1)        # t7 = A[*]
	add  $t6, $t6, $t7      # s =+ A[*]
        add  $t1, $t1, $t2      # adress += 4
        j    loop

loopend: sw   $t6, S           # $t3の値をsにストア 
