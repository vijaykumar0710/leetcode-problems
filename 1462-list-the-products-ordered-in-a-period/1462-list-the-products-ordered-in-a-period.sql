select product_name,SUM(unit) as unit
from Products 
join Orders 
on Products.product_id = Orders.product_id  
where DATE_FORMAT(Orders.order_date, '%Y-%m') = '2020-02'
group by product_name
HAVING SUM(unit)>=100;