# Write your MySQL query statement below
SELECT uni.unique_id, emp.name
FROM Employees as emp
LEFT JOIN EmployeeUNI as uni
ON emp.id = uni.id;