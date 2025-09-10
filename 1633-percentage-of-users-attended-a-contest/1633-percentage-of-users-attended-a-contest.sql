# Write your MySQL query statement below
Select contest_id,round(count(distinct user_id)*100/(select count(user_id) from users),2) as percentage from Register
GROUP BY contest_id
ORDER BY percentage desc,contest_id