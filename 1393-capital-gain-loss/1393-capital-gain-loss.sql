# Write your MySQL query statement below
SELECT stock_name,SUM(If(operation='Buy', -1*price,price)) as capital_gain_loss
from Stocks
group by stock_name;