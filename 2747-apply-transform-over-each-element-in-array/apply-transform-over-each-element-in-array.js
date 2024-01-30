/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transArray = [];
    arr.forEach((element, index) => {
        transArray[index] = fn(element, index);
    } );
    return transArray;
};