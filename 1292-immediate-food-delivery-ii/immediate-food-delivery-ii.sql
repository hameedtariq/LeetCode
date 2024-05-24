/* Write your PL/SQL query statement below */
With ranked_orders as (select d.*,
 ROW_NUMBER() OVER (PARTITION BY customer_id Order by order_date) as row_num 
from delivery d
)
select round(avg(case when order_date = customer_pref_delivery_date then 1 else 0 end)*100, 2) as immediate_percentage 
from ranked_orders
where row_num = 1;