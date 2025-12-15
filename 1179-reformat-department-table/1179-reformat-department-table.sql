# Write your MySQL query statement below
SELECT id,MAX( CASE WHEN month='jan' THEN revenue ELSE NULL END ) AS Jan_Revenue,
MAX( CASE WHEN month='jan' THEN revenue ELSE NULL END ) AS Jan_Revenue,
MAX( CASE WHEN month='jan' THEN revenue ELSE NULL END ) AS Jan_Revenue,

FROM Department
GROUP BY id