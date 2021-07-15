package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	ciphertext string
	keyword    string
)

// type includes {dec: decrypted string, key: key int}
type Decript_type struct {
	dec string
	key int
}

// Decrypt Function like gpp -> foo with key = 1
func CaesarDecrypt(key int32, plaintext string) string {
	// string to []byte
	c := []rune(plaintext)

	for i := range plaintext {
		if isAlphabet(&c[i]) {
			c[i] -= key
			// if the char overflowed, plus the alphabet length
			c[i] = charOverflowFilter(c[i], key)
		}
	}
	// return string casted encrypted text
	return string(c)
}

func charOverflowFilter(_rune rune, key int32) rune {

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

// check given bye lower alphabet or not
func isAlphabet(_byte *rune) bool {

	if *_byte >= 'a' && *_byte <= 'z' {
		return true
	} else if *_byte >= 'A' && *_byte <= 'Z' {
		return true
	}
	return false
}

// ----------------------------------------------------------

func BruteForceAttack(ciphertext *string, keyword *string) {

	// if keyword is empty...
	if *keyword == "" {
		showAll(ciphertext)
	} else {
		for _, v := range findAll(ciphertext, keyword) {
			fmt.Println("Plaintext after decryption with key= " + strconv.Itoa(v.key) + ": " + v.dec)
		}
	}
}

func showAll(ciphertext *string) {

	// show every CaesarDecrypted string with 1-25 keys.
	for i := 1; i <= 25; i++ {
		fmt.Println("Plaintext after decryption with key= " + strconv.Itoa(i) + ": " + CaesarDecrypt(int32(i), *ciphertext))
	}
}

func findAll(ciphertext *string, keyword *string) []Decript_type {

	found_array := []Decript_type{}
	// find one that include keyword inside the string
	for i := 1; i <= 25; i++ {

		var _decryption string = CaesarDecrypt(int32(i), *ciphertext)
		if strings.Contains(_decryption, *keyword) {
			found_array = append(found_array, Decript_type{_decryption, i})
		}
	}
	return found_array
}

// ----------------------------------------------------------

func main() {

	// open scanner class
	var scanner *bufio.Scanner = bufio.NewScanner(os.Stdin)

	// output "Input plaintext:"
	fmt.Print("Input ciphertext:")

	// read plaintext
	scanner.Scan()
	ciphertext = scanner.Text()

	// key variable scanner
	fmt.Print("Input keyword:")
	scanner.Scan()
	keyword := scanner.Text()

	// Start Brute Force Attack
	BruteForceAttack(&ciphertext, &keyword)

}

// cast string into int32
func stringToInt32(_st string) int32 {
	_intkey, _ := strconv.Atoi(_st)
	return int32(_intkey)
}
