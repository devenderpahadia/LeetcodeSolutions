# Write your MySQL query statement below

select product_id,product_name
from Product
where product_id not in (select product_id from Sales where EXTRACT(MONTH FROM sale_date)>3);