/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    var obj={
        toBe(x){
          if(val===x) return true;
          else throw new Error("Not Equal");
        },
        notToBe(x){
            if(x!==val) return true;
            else throw new Error("Equal");
        }
    }
    return obj;
};
expect(5).toBe(5);
expect(5).notToBe(null);
/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */