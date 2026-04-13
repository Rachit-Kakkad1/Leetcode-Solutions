/**
 * @param {number} init
 * @return {Object}
 */
var createCounter = function(init) {
    let value = init;

    return {
        increment: function() {
            value++;
            return value;
        },
        decrement: function() {
            value--;
            return value;
        },
        reset: function() {
            value = init;
            return value;
        }
    };
};
/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */