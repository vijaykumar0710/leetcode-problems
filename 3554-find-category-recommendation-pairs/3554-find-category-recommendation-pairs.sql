WITH cte AS(SELECT PP.*,PI.category
FROM ProductPurchases PP
LEFT JOIN ProductInfo PI
ON PP.product_id=PI.product_id)

SELECT c1.category as category1, c2.category as category2,COUNT(DISTINCT c1.user_id) AS customer_count 
FROM cte c1
LEFT JOIN cte c2
ON c1.user_id=c2.user_id
AND c1.category<c2.category
WHERE c2.category IS NOT NULL
GROUP BY c1.category, c2.category
HAVING customer_count>=3
ORDER BY customer_count DESC,category1,category2