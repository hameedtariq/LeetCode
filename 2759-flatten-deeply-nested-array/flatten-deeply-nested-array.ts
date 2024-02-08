type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    let x = [];
    if(n == 0 ) return arr;
    for(const item of arr) {
        if(typeof item === 'number'){
            x.push(item);
        }else {
            x.push(...flat(item, n-1));
        }
    }
    return x;
};
