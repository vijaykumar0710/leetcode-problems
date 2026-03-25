# Write your MySQL query statement below
WITH cte AS(SELECT *,
ROW_NUMBER() OVER(
    PARTITION BY user_id,action
    ORDER BY action_date
) AS 'rnk'
FROM activity),

cte2 AS(SELECT *,(action_date - INTERVAL rnk DAY) AS diff
FROM cte)

SELECT user_id,action,COUNT(*) AS streak_length,
       MIN(action_date) AS start_date, MAX(action_date) AS end_date
FROM cte2
GROUP BY user_id,action, diff
HAVING streak_length>=5
ORDER BY streak_length DESC,user_id