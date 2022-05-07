/**
 * @param {number} n
 * @return {number}
 */
var numberOfMatches = function(n) {
    var res = 0;
    while(n!=1)
    {
        if(n%2 == 0)
        {
            res = res + (n/2);
            n = n/2;
        }
        else
        {
            res = res + ((n-1)/2);
            n = (n-1)/2 + 1;
        }
    }
    return res;
};