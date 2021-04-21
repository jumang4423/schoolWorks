            .data
A:      .word 98     # A[0] = 98
        .word 76     # A[1] = 76
        .word 54
        .word 32
        .word 10
        .word 20
        .word 21
        .word 4      # A[7] = 4
        .word 15     # A[8] = 15
ADDRESS_A:  .word 20480   #00005000の10進表現
ADDRESS_B:  .word 20516   #00005000の10進表現
N:      .word 9    # The length of Array
B:      .space 36   # 配列B の格納先 大きさは36バイト
FOUR:   .word 4
ONE:    .word 1

            .text
main:   or   $t0, $0, $0
        lw   $t1, ADDRESS_A
        lw   $t2, FOUR
        lw   $t4, N
        lw   $t5, ONE
	lw   $t6, B
        lw   $t8, ADDRESS_B

loop:   beq  $t4, $t0, loopend
        add  $t0, $t0, $t5      # i++
        lw   $t7, 0($t1)        # t7 = A[*]
	lw   $t9, 0($t8)
	add   $t9, $9, $t7      # B[*] = A[*]
        add  $t1, $t1, $t2      # Aadress += 4
	add  $t8, $t8, $t2      # Badress += 4

        j    loop

loopend: sw   $t6, B
