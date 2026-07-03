var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const n = functions.length;
        const result = new Array(n);
        let completed = 0;
        if (n == 0) {
            resolve([]);
            return;
        }
        for (let i = 0; i < n; i++) {
            functions[i]()
                .then(value => {
                    result[i] = value;
                    completed++;
                    if (completed === n) {
                        resolve(result);
                    }
                })
                .catch(error => {
                    reject(error);
                });
        }
    });
};