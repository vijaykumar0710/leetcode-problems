# Write your MySQL query statement below
select distinct employee_id,department_id 
from Employee
where employee_id  IN(
    select employee_id  
    from Employee
    group by employee_id  
    having COUNT(*)=1 
) OR primary_flag ='Y'