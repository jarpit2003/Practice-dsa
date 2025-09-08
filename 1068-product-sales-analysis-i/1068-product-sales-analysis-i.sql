# Write your MySQL query statement below
Select  product_name, year, price from Sales as s
LEFT JOIN Product as p ON s.product_id = p.product_id ;