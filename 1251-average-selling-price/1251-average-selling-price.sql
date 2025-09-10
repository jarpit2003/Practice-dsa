# Write your MySQL query statement below
Select p.product_id ,IFNULL(ROUND(SUM(p.price*up.units)/SUM(up.units),2),0)AS average_price 
FROM Prices as p LEFT JOIN UnitsSold as up ON
p.product_id = up.product_id
AND up.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;