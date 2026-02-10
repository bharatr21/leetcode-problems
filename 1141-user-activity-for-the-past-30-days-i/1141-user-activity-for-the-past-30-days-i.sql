-- Write your PostgreSQL query statement below
SELECT activity_date as day, COUNT(DISTINCT user_id) as active_users
FROM Activity
WHERE activity_date BETWEEN '2019-07-27'::date - INTERVAL '29 days' AND '2019-07-27'
GROUP BY activity_date;