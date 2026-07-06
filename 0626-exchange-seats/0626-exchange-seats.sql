SELECT
    s1.id,
    CASE
        WHEN s1.id % 2 = 1 AND s1.id != (SELECT MAX(id) FROM Seat)
           THEN s2.student
        WHEN s1.id % 2 = 0
           THEN S3.student
        ELSE s1.student
    END AS student
FROM Seat s1
LEFT JOIN Seat s2
     ON s1.id + 1 = s2.id
LEFT JOIN Seat s3
    ON s1.id - 1 = s3.id
ORDER BY s1.id;

