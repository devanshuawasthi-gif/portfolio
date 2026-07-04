var compactObject = function(obj) {

    if (Array.isArray(obj)) {
        const res = [];

        for (const val of obj) {
            const compacted = compactObject(val);
            if (Boolean(compacted)) {
                res.push(compacted);
            }
        }

        return res;
    }

    if (obj !== null && typeof obj === "object") {
        const res = {};

        for (const key in obj) {
            const compacted = compactObject(obj[key]);
            if (Boolean(compacted)) {
                res[key] = compacted;
            }
        }

        return res;
    }

    return obj;
};