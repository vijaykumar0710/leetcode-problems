select ROUND(SUM(IF(order_date=customer_pref_delivery_date,1,0))*100/COUNT(customer_id),2) as immediate_percentage 
from Delivery
WHERE(customer_id,order_date) IN
(select customer_id,MIN(order_date)
from Delivery
group by customer_id)