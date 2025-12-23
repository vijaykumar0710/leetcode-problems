# Write your MySQL query statement below
SELECT id,(CASE 
           WHEN p_id IS null THEN "Root"
           WHEN id NOT IN(SELECT p_id FROM Tree WHERE p_id IS NOT null) THEN "Leaf"
           ELSE "Inner" 
           END) AS type
FROM Tree