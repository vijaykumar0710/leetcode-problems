# Write your MySQL query statement below
SELECT *
FROM Users
WHERE email REGEXP '^[a-zA-z0-9_]+@[a-zA-Z]+[\.]com$'
ORDER BY user_id; 