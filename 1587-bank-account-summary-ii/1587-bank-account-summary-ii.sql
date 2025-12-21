WITH cte AS( 
 SELECT account,SUM(amount) as balance
 FROM Transactions
 GROUP BY account
 HAVING SUM(amount)>10000
) 
SELECT u.name,c.balance
FROM cte c
JOIN Users u
ON c.account=u.account