package main

import (
	"math/rand"
	"testing"

	"github.com/stretchr/testify/assert"
)

const MaxSize int = 32767

func TestSort(t *testing.T) {
	size := 0
	for size <= 0 {
		size = rand.Intn(MaxSize)
	}

	expect := make([]int, size)
	for index := 0; index < size; index++ {
		expect[index] = rand.Int()
	}

	exact := make([]int, size)
	copy(exact, expect)

	Sort(exact)

	assert.IsIncreasing(t, exact)
	assert.ElementsMatch(t, expect, exact)
}
