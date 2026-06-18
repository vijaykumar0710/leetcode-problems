/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let n=nums.length;
    let map=new Map();
    for(let i=0;i<n;i++){
       let need=target-nums[i];
       if(map.has(need)) return [i,map.get(need)];
       map.set(nums[i],i);
    }
    return [];
};