/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let indices = new Array();
    let index_0, index_1;
    let isFinished = false;
    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < nums.length; j++) {
            if(j === i) {
                continue;
            }
            if((nums[i] + nums[j]) === target) {
                index_0 = i;
                index_1 = j;
                indices.push(index_0);
                indices.push(index_1);
                isFinished = true;
                 break;
            }
        }
        if(isFinished) {
            break;
        }
    }
    return indices;
};