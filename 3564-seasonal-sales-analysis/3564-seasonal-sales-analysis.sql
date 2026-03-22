WITH cte As(
    SELECT products.category,SUM(sales.quantity) AS 'total_quantity',
        SUM(sales.price*sales.quantity) AS 'total_revenue',
        CASE 
          WHEN MONTH(sale_date) IN(9,10,11) THEN 'Fall'
          WHEN MONTH(sale_date) IN(3,4,5) THEN 'Spring'
          WHEN MONTH(sale_date) IN(6,7,8) THEN 'Summer'
          WHEN MONTH(sale_date) IN(12,1,2) THEN 'Winter'
        END AS 'season'
    FROM sales
    JOIN products 
    ON sales.product_id=products.product_id
    GROUP BY season,category
   ),
   cte2 AS(
    SELECT season,category,total_quantity,total_revenue,
    ROW_NUMBER() OVER(
        PARTITION BY season
        ORDER BY 
          total_quantity DESC,
          total_revenue DESC,
          category
    ) AS 'rank_num'
    FROM cte
   )

   SELECT season,category,total_quantity,total_revenue
   FROM cte2
   WHERE rank_num=1;