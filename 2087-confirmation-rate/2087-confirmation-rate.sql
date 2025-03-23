# Write your MySQL query statement below
SELECT s.user_id, 
CASE WHEN c.user_id IS NULL THEN 0
ELSE ROUND(SUM(c.action = 'Confirmed') / COUNT(c.user_id), 2) END AS confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c
ON s.user_id = c.user_id
GROUP BY s.user_id;