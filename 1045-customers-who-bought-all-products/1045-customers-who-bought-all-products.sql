# Write your MySQL query statement below
Select  customer_id from Customer C 
GROUP BY customer_id HAVING COUNT(distinct product_key) = (SELECT COUNT(product_key) FROM Product)