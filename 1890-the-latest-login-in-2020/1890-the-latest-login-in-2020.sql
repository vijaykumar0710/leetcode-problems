# Write your MySQL query statement below
SELECT user_id,MAX(time_stamp) AS last_stamp
FROM Logins
WHERE time_stamp like '2020%'
GROUP BY user_id