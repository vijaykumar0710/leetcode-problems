# Write your MySQL query statement below
WITH cte1 AS(
    SELECT DISTINCT salary
     FROM Employee 
),
cte2 AS (SELECT NTH_VALUE(salary,2) OVER(
                   ORDER BY salary DESC
                   ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING
  ) AS sa
FROM cte1)

SELECT MAX(sa) as SecondHighestSalary
FROM cte2;