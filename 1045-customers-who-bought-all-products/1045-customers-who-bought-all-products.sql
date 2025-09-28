# Write your MySQL query statement below
Select customer_id from Customer
GROUP BY  customer_id
HAVING COUNT(DISTINCT product_key) = (Select Count(product_key)from Product)