/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(nums) {
    var res = [];
    for(let i = 0;i<nums.length;i++)
    {
        for(let j = 0;j<nums[i].length;j++)
        {
            var x = 100001;
            var y = -1;
            for(let k = 0;k<nums[i].length;k++)
            {
                x = Math.min(x,nums[i][k]);
            }
            for(let k = 0;k<nums.length;k++)
            {
                y = Math.max(y,nums[k][j]);
            }
            if(x==nums[i][j] && y==nums[i][j])
            {
                res.push(x);
            }
        }
    }
    return res;
};