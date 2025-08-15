/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const mpp = {} ;

    this.forEach((elem)=>{
        let key = fn(elem) ;
       if(!mpp[key]){
        mpp[key] = [] ;
       }

       mpp[key].push(elem) ;
    })
    return mpp ;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */