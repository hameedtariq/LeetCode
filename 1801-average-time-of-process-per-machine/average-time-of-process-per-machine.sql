/* Write your PL/SQL query statement below */
-- select machine_id,count(process_id) from activity where activity_type  = 'start' group by machine_id ;
/* Write your PL/SQL query statement below */

SELECT machine_id, ROUND(SUM(CASE WHEN activity_type = 'start' THEN -timestamp ELSE timestamp END) / COUNT(DISTINCT process_id), 3) processing_time
FROM Activity
group by machine_id