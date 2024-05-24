/* Write your PL/SQL query statement below */
select a.machine_id as "machine_id", ROUND(AVG(b.timestamp - a.timestamp),3) as "processing_time" 
from (select * from Activity where activity_type='start') a 
join (select * from Activity where activity_type='end') b 
on a.machine_id = b.machine_id and b.process_id = a.process_id
group by a.machine_id
order by "machine_id" ;