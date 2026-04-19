# Write your MySQL query statement below
SELECT name,population,area 
FROM World
HAVING area>=3000000 || population >=25000000;