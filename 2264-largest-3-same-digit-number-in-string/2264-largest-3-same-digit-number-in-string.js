/**
 * @param {string} num
 * @return {string}
 */
var largestGoodInteger = function(num) {
    if(num.includes("999"))
    {
        return "999";
    }
    else if(num.includes("888"))
    {
        return "888";
    }
    else if(num.includes("777"))
    {
        return "777";
    }
    else if(num.includes("666"))
    {
        return "666";
    }
    else if(num.includes("555"))
    {
        return "555";
    }
    else if(num.includes("444"))
    {
        return "444";
    }
    else if(num.includes("333"))
    {
        return "333";
    }
    else if(num.includes("222"))
    {
        return "222";
    }
    else if(num.includes("111"))
    {
        return "111";
    }
    else if(num.includes("000"))
    {
        return "000";
    }
    return "";
};