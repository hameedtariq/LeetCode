-- Write your PostgreSQL query statement below
select project_id, round(avg(employee.experience_years),2) as average_years
from project
join employee
using(employee_id)
group by project_id
order by project_id asc