package leetcode

/**
 * Problem #96
 * https://leetcode.com/problems/unique-binary-search-trees/
 */

func numTrees(n int) int {
	var vals []int
	vals = make([]int, n+1)

	vals[0] = 1
	vals[1] = 1

	for i := 2; i <= n; i++ {
		l := 0
		r := i - 1
		for l <= i-1 {
			vals[i] += vals[l] * vals[r]
			l += 1
			r -= 1
		}
	}

	return vals[n]
}
