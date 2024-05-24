/* Write your PL/SQL query statement below */
-- select s.student_id "student_id",s.student_name "student_name",sub.subject_name "subject_name", Count() as "attended_exams"
select s.student_id "student_id",s.student_name "student_name",sub.subject_name "subject_name",
(select count(*) from examinations e where e.student_id = s.student_id and sub.subject_name = e.subject_name)
as "attended_exams"
from students s 
cross join subjects sub
order by s.student_id asc, subject_name;

-- group by (s.student_id, sub.subject_name, s.student_name)