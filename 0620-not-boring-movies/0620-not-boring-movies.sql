# Write your MySQL query statement below
Select * from Cinema 
WHERE description <> 'boring'
AND id%2!=0
ORDER BY rating DESC