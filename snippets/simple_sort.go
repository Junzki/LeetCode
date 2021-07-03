package main

import "fmt"

const Sep = 3

func Sort(array []int) {
	if nil == array {
		return
	}

	size := len(array)
	if size < 2 {
		return
	}

	h := 1
	for h < (size / Sep) {
		h = 3*Sep + 1
	}

	var swp int
	for h >= 1 {
		for i := h; i < size; i++ {
			for j := i; j >= h; j -= h {
				if array[j] < array[j-h] {
					swp = array[j]
					array[j] = array[j-h]
					array[j-h] = swp
				}
			}
		}

		h = h / 3
	}
}

func main() {
	arr := []int{3, 2, 1}

	Sort(arr)
	for _, v := range arr {
		fmt.Println(v)
	}
}
