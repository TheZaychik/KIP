package main

import (
	"fmt"
	"math"
)

func main() {
	var summaVklada float64
	var procentVklada float64
	var numberofyears float64
	fmt.Print("Введите сумму вклада: ")
	fmt.Scanln(&summaVklada)
	fmt.Print("Введите годовой процент: ")
	fmt.Scanln(&procentVklada)
	fmt.Println("Процент вклада: ", procentVklada);
	fmt.Print("Введите количество лет вклада: ")
	fmt.Scanln(&numberofyears)
	fmt.Println("Количество лет вклада: ", numberofyears);
	mounth := numberofyears
	SummaEnd := summaVklada
	for year := 1.0; year <= numberofyears; year++ {
		SummaEnd = SummaEnd + SummaEnd*procentVklada/100
		SummaEnd = SummaEnd * 100
		SummaEnd = math.Round(SummaEnd)
		SummaEnd = SummaEnd / 100
		mounth = mounth - 1
	}
	if mounth != 0 {
		mounth = 1 / mounth;
		SummaEnd = SummaEnd + SummaEnd*procentVklada/(100*mounth)
		SummaEnd = SummaEnd * 100
		SummaEnd = math.Round(SummaEnd)
		SummaEnd = SummaEnd / 100
	}
	SummaEnde := int64(SummaEnd)
	fmt.Println("Итоговая сумма: ", SummaEnde);
}
