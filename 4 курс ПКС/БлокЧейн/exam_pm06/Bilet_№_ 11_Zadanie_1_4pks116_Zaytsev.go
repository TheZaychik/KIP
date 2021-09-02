package main

import "fmt"

const exchange = 3.992956 // ZAR

func main() {
	var amount float64
	fmt.Println("Input a number of RUB to exchange on ZAR")
	fmt.Scanln(&amount)
	fmt.Println(amount, "RUB exchanges by", exchange, "course to", amount/exchange, "ZAR")
}
