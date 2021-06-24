package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	plaintext   string
	ciphertext  string
	decrypttext string
	key         int32 = -1
)

// Encrypt Function like foo -> gpp with key = 1
func CaesarEncrypt(key int32, plaintext string) string {
	// string to []byte
	c := []rune(plaintext)

	for i := range plaintext {
		c[i] += key
		// if the char overflowed, minus the alphabet length
		c[i] = charOverflowFilter(c[i], key, true)
	}
	// return string casted encrypted text
	return string(c)
}

// Decrypt Function like gpp -> foo with key = 1
func CaesarDecrypt(key int32, plaintext string) string {
	// string to []byte
	c := []rune(plaintext)

	for i := range plaintext {
		c[i] -= key
		// if the char overflowed, plus the alphabet length
		c[i] = charOverflowFilter(c[i], key, false)
	}
	// return string casted encrypted text
	return string(c)
}

func charOverflowFilter(_rune rune, key int32, isEncrypt bool) rune {

	if isEncrypt {
		if _rune-key >= 'A' && 'Z' >= _rune-key {
			if 'Z' < _rune {
				_rune -= 'Z' - '@'
			}
		} else if _rune-key >= 'a' && 'z' >= _rune-key {
			if 'z' < _rune {
				_rune -= 'z' - '`'
			}
		} else {
			_rune = ' '
		}

		return _rune
	} else {
		if _rune+key >= 'A' && 'Z' >= _rune+key {
			if 'A' > _rune {
				_rune += 'Z' - '@'
			}
		} else if _rune+key >= 'a' && 'z' >= _rune+key {
			if 'a' > _rune {
				_rune += 'z' - '`'
			}
		} else {
			_rune = ' '
		}

		return _rune
	}

}

func main() {

	// open scanner class
	var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)

	// output "Input plaintext:"
	fmt.Print("Input plaintext:")

	// read plaintext
	scanner.Scan()
	plaintext = scanner.Text()

	// key variable scanner
	for key < 0 || key > 25 {
		fmt.Print("Input key (0<=key=<25):")
		scanner.Scan()
		_tmp := scanner.Text()
		key = stringToInt32(_tmp)
	}

	// plaintext to ciphertext
	ciphertext = CaesarEncrypt(key, plaintext)

	// ciphertext to plaintext
	decrypttext = CaesarDecrypt(key, ciphertext)

	fmt.Println("Plaintext: " + plaintext + "\n")
	fmt.Println("Ciphertext: " + ciphertext)
	fmt.Println("Decrypted plaintext:" + decrypttext)

}

func stringToInt32(_st string) int32 {
	_intkey, _ := strconv.Atoi(_st)
	return int32(_intkey)
}
