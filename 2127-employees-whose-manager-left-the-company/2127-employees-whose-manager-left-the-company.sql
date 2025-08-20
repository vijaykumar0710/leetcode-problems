    select employee_id 
    from Employees e
    where salary<30000 && manager_id NOT IN(
        select employee_id
        from Employees e
        )
        order by employee_id