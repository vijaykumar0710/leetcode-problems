# Write your MySQL query statement below
SELECT e.name as name
FROM Employee e
JOIN Employee m
ON e.id=m.managerId 
GROUP BY e.id
HAVING COUNT(e.id)>=5;