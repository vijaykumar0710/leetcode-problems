# Write your MySQL query statement below
SELECT customer_id
FROM customer_transactions 
GROUP BY customer_id
HAVING COUNT(*)>=3 &&
       DATEDIFF(MAX(transaction_date),MIN(transaction_date))>=30 &&
      (SUM(transaction_type="refund")*100/COUNT(customer_id))<20
ORDER BY customer_id;