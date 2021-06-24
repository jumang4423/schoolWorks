package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
	"unicode"
)

var (
	ciphertext string = "ztmn pxtne cfa peqef kecnp cjt tmn zcwsenp ontmjsw ztnws tf wsvp xtfwvfefw, c feb fcwvtf, xtfxevqea vf gvoenwk, cfa aeavxcwea wt wse rntrtpvwvtf wscw cgg lef cne xnecwea eymcg"
	plaintext  string
	subs       string
)

// struct incidence_pair
type incidence_pair struct {
	c    byte
	freq float64
}

// ----------------------------------------------------------

func getIncidence(ciphertext *string) []incidence_pair {

	incidence := []incidence_pair{}
	array_ciphertext := []byte(*ciphertext)

	// prepare index of incidence
	for i := 0; i <= 25; i++ {
		incidence = append(incidence, incidence_pair{byte(i) + 'a', 0})
	}

	// collect alphabets
	for _, v := range array_ciphertext {
		// if cipher rune is alphabet...
		if v >= 'a' && v <= 'z' {
			incidence[v-'a'].freq += 1.0 / float64(len(array_ciphertext))
		}
	}

	// sort by freq: float of incidence_pair
	sort.Slice(incidence, func(i, j int) bool { return incidence[i].freq > incidence[j].freq })

	return incidence
}

func monoalphabetic_substitution(ciphertext *string, subs *string) string {

	// LOWER cipher -> CAPITALIZED cipher
	var transformed_ciphertext string = strings.ToUpperSpecial(unicode.TurkishCase, *ciphertext)
	var array_subs []byte = []byte(*subs)
	for i := len(array_subs); i < 26; i++ {
		array_subs = append(array_subs, ' ')
	}

	for i, v := range array_subs {
		// if v is lower alphabet
		if isLowerAlphabet(v) {
			// v -> i + 'a'
			transformed_ciphertext = strings.Replace(transformed_ciphertext, string(byte(i)+'A'), string(v), -1)
		} else if v == ' ' {
			// ' ' -> 'a'
			transformed_ciphertext = strings.Replace(transformed_ciphertext, string(byte(i)+'A'), " ", -1)
		}
	}

	return transformed_ciphertext
}

// check given bye lower alphabet or not
func isLowerAlphabet(_byte byte) bool {

	if _byte >= 'a' && _byte <= 'z' {
		return true
	}
	return false
}

// ----------------------------------------------------------

func main() {
	// argument validation
	if len(os.Args[1:]) != 1 {
		fmt.Println("Not enough or too many arguments!")
		os.Exit(1)
	}

	// take subs from first argument
	subs = os.Args[1]

	// make getIncidenced incidence_pair
	var ip []incidence_pair = getIncidence(&ciphertext)

	// if subs were empty, show
	if subs == "" {
		for i := 0; i <= 25; i++ {
			fmt.Println(string(ip[i].c) + ":" + strconv.FormatFloat(ip[i].freq, 'f', 6, 64))
		}
	}

	// print monoalphabetic_substituted string
	fmt.Println("Potential Plaintext: " + monoalphabetic_substitution(&ciphertext, &subs))
}
