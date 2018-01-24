package main

import (
    "fmt"
)

func twoSumA(nums []int, target int) []int {
    var m map[int]int
    m = make(map[int]int)
    for k, v := range nums {
        m[v] = k
    }
    for k, v := range nums {
        if _, ok := m[target-v]; ok {
            if m[target-v] == k {
                continue
            } else {
                return []int{k, m[target-v]}
            }
        }
    }
    return []int{}
}

func twoSum(nums []int, target int) []int {
    for i,v1 := range nums{
	if i+1 != len(nums){
	    for j, v2 := range nums[i+1:] { 
		if target == (v1 + v2) {
		    return []int{i, i+j+1}
		}
	    }
	}
    }
    return []int{}
}

func main() {
    nums := []int{2, 7, 11, 15}
    fmt.Println(nums[0:])
    target := 9
    output := twoSumA(nums, target)
    fmt.Println(output)
}