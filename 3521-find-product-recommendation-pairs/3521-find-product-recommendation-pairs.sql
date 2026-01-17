# Write your MySQL query statement below
WITH cte AS(
    SELECT ProductPurchases.user_id,
           ProductPurchases.product_id,
           ProductInfo.category
    FROM ProductPurchases
    JOIN ProductInfo
    ON ProductPurchases.product_id=ProductInfo.product_id
)

SELECT p1.product_id AS product1_id,
       p2.product_id AS product2_id,
       p1.category AS product1_category,
       p2.category AS product2_category,
       COUNT(DISTINCT p1.user_id) AS customer_count
FROM cte p1
JOIN cte p2
ON p1.user_id=p2.user_id AND p1.product_id<p2.product_id
GROUP BY p1.product_id,
         p2.product_id
HAVING COUNT(DISTINCT p1.user_id)>=3
ORDER BY customer_count DESC,
         product1_id ASC,
         product1_id ASC