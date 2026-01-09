# Write your MySQL query statement below
WITH cte AS(
    SELECT user_id,
           COUNT(prompt) AS prompt_count,
           MAX(tokens) AS max_token,
           ROUND(SUM(tokens)/COUNT(*),2) AS avg_tokens
    FROM prompts
    GROUP BY user_id
)

SELECT user_id,
       prompt_count,
       avg_tokens
FROM cte
WHERE prompt_count>=3 AND max_token>avg_tokens
ORDER BY avg_tokens DESC,user_id ASC