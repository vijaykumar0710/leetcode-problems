select IFNULL(
(select distinct salary 
from Employee
ORDER BY salary desc
LIMIT 1 OFFSET 1),
null ) as SecondHighestSalary