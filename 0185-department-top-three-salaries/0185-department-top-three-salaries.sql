SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d
ON e.departmentId=d.id
WHERE(
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e.departmentId=e2.departmentId && e.salary<=e2.salary
)<=3;