# Write your MySQL query statement below
select 
c.customer_id
from Customer c
group by customer_id
Having count(distinct c.product_key) = (select count(*) from Product)
order by customer_id asc;