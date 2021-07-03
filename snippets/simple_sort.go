package main

import "fmt"

func Sort(array []int) {
	if nil == array {
		return
	}

	size := len(array)
	if size < 2 {
		return
	}

	for index := 0; index < size; index++ {
		var v1 int = array[index]
		var v2 int

		for inside := index; inside < size; inside++ {
			v2 = array[inside]
			if v2 < v1 {
				array[index] = v2
				array[inside] = v1
				v1 = v2
			}
		}
	}
}

func main() {
	arr := []int{3, 2, 1}

	Sort(arr)
	for _, v := range arr {
		fmt.Println(v)
	}
}
