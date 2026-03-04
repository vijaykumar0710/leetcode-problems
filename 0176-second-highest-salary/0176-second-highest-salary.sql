WITH cte AS (SELECT salary,
             DENSE_RANK() OVER(ORDER BY salary DESC) AS rank_num
FROM Employee
) 
SELECT MAX(salary) as SecondHighestSalary 
FROM cte
WHERE rank_num=2;