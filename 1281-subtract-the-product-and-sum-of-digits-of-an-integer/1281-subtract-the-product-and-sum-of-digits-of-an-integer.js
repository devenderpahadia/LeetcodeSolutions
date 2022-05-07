/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    var pro = 1;
    var sum = 0;
    var res = n;
    while(res)
    {
        pro = pro*(res%10);
        sum = sum + (res%10);
        res= Math.floor( res/10);
    }
    // console.log(pro+" "+sum);
    return pro-sum;
};