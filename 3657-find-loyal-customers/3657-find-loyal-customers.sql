# Write your MySQL query statement below
SELECT customer_id
FROM customer_transactions 
GROUP BY customer_id
HAVING COUNT(customer_id)>=3 &&
       DATEDIFF(MAX(transaction_date),MIN(transaction_date))>=30 &&
      (SUM(IF(transaction_type="refund",1,0))*100/COUNT(customer_id))<20
ORDER BY customer_id;