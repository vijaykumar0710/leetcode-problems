# Write your MySQL query statement below
WITH
 cte As(
    SELECT buyer_id,COUNT(*) as cnt
    FROM Orders
    WHERE YEAR(order_date)=2019
    GROUP BY buyer_id
),
cte2 AS(SELECT u.user_id AS buyer_id,u.join_date,c.cnt AS orders_in_2019
FROM Users u
LEFT JOIN cte c
ON u.user_id=c.buyer_id)

SELECT buyer_id,join_date,COALESCE(orders_in_2019,0) AS orders_in_2019
FROM cte2