# s1270174
        .data
A:      .word 9988
B:      .word 7766
C:      .word 0

        .text
main:   or   $t0, $0, $0  # 最下位ビットが入る
        lw   $t1, A     # 左シフトしていく
        lw   $t2, B     # 不変
        lw   $t3, C
        addi   $t4, $0, 16
        addi $t8, $0, 1    #１の代入 tempo

loop:   beq  $t4, $t0, loopend
        and $t9, $t2, $t8     # Bの最下位ビットの取得
        beq $t9, $0, shift       #最下位ビットが１なら

	  add $t3, $t3, $t1   # 計算結果に数値を足す
        j    shift

shift:
        add $t8, $t8, $t8   # tempoの左シフト
        add $t1, $t1, $t1  # Aの左シフト
        addi $t0, $t0, 1 
        j    loop

loopend: sw   $t3, C           # $t3の値をCにストア
         j    exit

exit: j exit