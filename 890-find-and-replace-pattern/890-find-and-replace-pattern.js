/**
 * @param {string[]} words
 * @param {string} pattern
 * @return {string[]}
 */
var findAndReplacePattern = function(words, pattern) {
    var res = [];
    for(let i = 0;i<words.length;i++)
    {
        var flag = 1;
        var mp = new Map();
        var str = words[i];
        if(str.length != pattern.length)
        {
            continue;
        }
        for(let k = 0;k<str.length;k++)
        {
            if(mp.has(pattern[k]))
            {
                if(mp.get(pattern[k])!=str[k])
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                mp.set(pattern[k],str[k]);
            }
        }
        mp.clear();
        for(let k = 0;k<str.length;k++)
        {
            if(mp.has(str[k]))
            {
                if(mp.get(str[k])!=pattern[k])
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                mp.set(str[k],pattern[k]);
            }
        }
        if(flag)
            res.push(words[i]);
    }
    return res;
};