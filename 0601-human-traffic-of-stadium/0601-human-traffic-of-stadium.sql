# Write your MySQL query statement below
WITH cte AS(
    SELECT *,id-ROW_NUMBER() OVER(ORDER BY id) AS diff
    FROM Stadium
    WHERE people>=100
    )

SELECT cte.id,cte.visit_date,cte.people
FROM cte
WHERE diff
IN
(SELECT diff
FROM cte
GROUP BY diff
HAVING COUNT(diff)>=3)
ORDER BY visit_date