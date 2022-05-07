/**
 * @param {string} boxes
 * @return {number[]}
 */
var minOperations = function(boxes) {
    var ans = [];
    for(let i = 0;i<boxes.length;i++)
    {
        var res = 0;
        for(let j = 0 ; j<boxes.length;j++)
        {
            if(i!=j)
            {
                if(boxes[j]=='1')
                {
                    res= res + (Math.abs(j-i));
                }
            }
        }
        ans.push(res);
    }
    return ans;
};