select visited_on,
(
    select SUM(amount)
    from Customer
    where visited_on BETWEEN DATE_SUB(c.visited_on,INTERVAL 6 DAY)
    and c.visited_on
) as amount,
ROUND((
    select SUM(amount)/7
    from Customer
    where visited_on BETWEEN DATE_SUB(c.visited_on,INTERVAL 6 DAY)
    and c.visited_on
),2) as average_amount
from Customer c
where visited_on>=(
    select DATE_ADD(MIN(visited_on),INTERVAL 6 DAY)
    from Customer
)
group by visited_on
order by visited_on