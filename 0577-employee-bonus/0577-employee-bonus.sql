# Write your MySQL query statement below
SELECT em.name, b.bonus
FROM Employee AS em
LEFT JOIN Bonus AS b
ON em.empId = b.empId
WHERE b.bonus IS NULL or b.bonus < 1000;