# Write your MySQL query statement below
-- SELECT name,travelled_distance 
-- FROM Users
-- WHERE travelled_distance IN(
--     SELECT SUM(distance)
--     FROM Rides
--     GROUP BY user_id
-- )

SELECT u.name , IF(SUM(r.distance)>0,SUM(r.distance),0) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id=r.user_id
GROUP BY u.id
ORDER BY travelled_distance DESC, name ASC