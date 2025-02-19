package main

import "fmt"

func GetMaxLen(words []string) int {
	maxLen := 0
	for _, s := range words {
		maxLen = max(maxLen, len(s))
	}

	return maxLen
}

func Match(words []string, word string) bool {
	for _, w := range words {
		if w == word {
			return true
		}
	}

	return false
}

func WordBreak(s string, w []string) bool {
	maxLen := GetMaxLen(w)
	for i := 0; i < len(s); {
		gotOne := false
		for l := 1; l <= min(maxLen, len(s)-i); l++ {
			word := s[i : i+l]
			if Match(w, word) {
				gotOne = true
				i += l
				break
			}
		}
		if !gotOne {
			return false
		}
	}

	return true
}

func main() {
	for {
		fmt.Print("The string to split: ")
		var str string
		fmt.Scan(&str)
		if str == "q" || str == "Q" {
			break
		}

		fmt.Print("Number of words to match: ")
		var count int
		fmt.Scan(&count)

		fmt.Print("Enter the words to match: ")
		words := make([]string, count)
		for i := 0; i < count; i++ {
			fmt.Scan(&words[i])
		}

		fmt.Print("The string can ")
		if !WordBreak(str, words) {
			fmt.Print("not ")
		}
		fmt.Println("be broken down!")
	}
}
