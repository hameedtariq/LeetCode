-- Write your PostgreSQL query statement below
-- select *
select p.product_id, 
    ROUND(
        SUM(p.price * COALESCE(us.units, 0))::decimal 
        / COALESCE(NULLIF(SUM(COALESCE(us.units, 0)), 0),1), 
        2
    ) AS average_price
from prices p 
left join unitssold us 
on p.product_id = us.product_id 
and us.purchase_date between p.start_date 
and p.end_date
group by p.product_id;