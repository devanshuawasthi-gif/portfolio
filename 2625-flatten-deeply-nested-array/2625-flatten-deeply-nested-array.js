var flat = function(arr, depth) {
    const result = [];

    function flatten(array, currentDepth) {
        for (const item of array) {
            if (Array.isArray(item) && currentDepth < depth) {
                flatten(item, currentDepth + 1);
            } else {
                result.push(item);
            }
        }
    }

    flatten(arr, 0);
    return result;
};