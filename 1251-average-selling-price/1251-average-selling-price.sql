# Write your MySQL query statement below
Select p.product_id, IFNULL(Round(sum(p.price* u.units)/SUM(u.units),2), 0) as average_price
 FROM Prices p
 Left join UnitsSold u
 on p.product_id= u.product_id
 AND u.purchase_date >= start_date 
 AND u.purchase_date <=end_date
  group by p.product_id;