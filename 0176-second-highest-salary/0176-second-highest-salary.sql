# Write your MySQL query statement below
WITH cte as(
    select *,
      DENSE_RANK() OVER(ORDER BY salary DESC) as "rnk"
      FROM Employee
)
SELECT MAX(salary) as "SecondHighestSalary"
FROM cte
WHERE rnk=2;