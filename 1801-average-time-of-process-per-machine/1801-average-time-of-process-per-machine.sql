# Write your MySQL query statement below
select machine_id,ROUND(SUM(IF(activity_type='end',1,-1)*timestamp)/COUNT(distinct(process_id )),3) as processing_time 
from Activity 
group by machine_id; 