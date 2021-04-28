        .data
A:      .word 9988
B:      .word 7766
C:      .word 0
one:    .word 1


        .text
main:   or   $t0, $0, $0
        lw   $t1, A     # 不変
        lw   $t2, B     # 左シフトしていく
        lw   $t3, C
        and   $t4, $0, 16
        lw   $t5, one
        or   $t0, $0, $0    # 最下位ビットが入る
        addi $t8, $0, 1    #１の代入 tempo

loop:   beq  $t4, $t0, loopend

        and $t9, $t2, $t10     # Bの最下位ビットの取得
        beq $t9, $t5, calc       #最下位ビットが１なら

        add $t8, $t8, $t8   # tempoの左シフト
        add $t1, $t1, $t1  # Aの左シフト
        j    loop

calc: add $t3, $t3, $t1

loopend: sw   $t3, S           # $t3の値をCにストア 
