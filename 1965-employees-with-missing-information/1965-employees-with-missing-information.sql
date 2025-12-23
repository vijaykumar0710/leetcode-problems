# Write your MySQL query statement below
WITH cte AS(SELECT employee_id
FROM Employees
UNION ALL
SELECT employee_id
FROM Salaries),
 cte1 AS(
SELECT employee_id,COUNT(employee_id) AS employee_id_count
FROM cte
GROUP BY employee_id
ORDER BY employee_id
)

SELECT employee_id
FROM cte1
WHERE employee_id_count=1