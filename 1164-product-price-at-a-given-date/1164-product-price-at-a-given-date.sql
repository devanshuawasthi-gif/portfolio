SELECT
    p.product_id,
    COALESCE(pr.new_price, 10) AS price
FROM
    (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN
    Products pr
ON p.product_id = pr.product_id
AND (pr.product_id, pr.change_date) IN (
    SELECT product_id, MAX(change_date)
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id
);
