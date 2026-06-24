// Program which duplicates the functionality of the Unix 'echo' command
package main

import (
	"fmt"
	"os"
)

func main() {
	var s, sep string
	for i := 1; i < len(os.Args); i++ {
		s += sep + os.Args[i] // Concatenation
		sep = " "
	}
	fmt.Println(s)
	fmt.Println(os.Args[0])
}
