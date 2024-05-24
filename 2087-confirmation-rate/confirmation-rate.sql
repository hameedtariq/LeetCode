/* Write your PL/SQL query statement below */
select s.user_id, ROUND(count(case action when 'confirmed' then 1 else null end)/count(*), 2) as confirmation_rate
-- select *
from Confirmations c
right join Signups s
on c.user_id = s.user_id
group by s.user_id;