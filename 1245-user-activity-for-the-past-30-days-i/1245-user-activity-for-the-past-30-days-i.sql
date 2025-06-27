# Write your MySQL query statement below
select activity_date as day,COUNT(DISTINCT user_id) as active_users 
from Activity
where DATEDIFF('2019-07-27',Activity.activity_date) between 0 and 29
group by activity_date ;