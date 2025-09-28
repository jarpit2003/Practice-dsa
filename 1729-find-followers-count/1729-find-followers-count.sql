# Write your MySQL query statement below
Select user_id,Count(follower_id) as followers_count
from Followers
GROUP BY user_id
ORDER BY user_id