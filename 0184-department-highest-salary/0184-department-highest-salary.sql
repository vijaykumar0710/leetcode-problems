# Write your MySQL query statement below
WITH cte AS(
    SELECT MAX(salary) AS salary,departmentId
    FROM Employee
    GROUP BY departmentId
)

SELECT d.name AS Department,e.name AS Employee,e.salary AS Salary
FROM Employee e
JOIN cte
ON e.departmentId=cte.departmentId && e.salary=cte.salary
JOIN Department d
ON d.id=e.departmentId