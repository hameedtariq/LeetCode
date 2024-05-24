/* Write your PL/SQL query statement below */
select name, bonus from Employee e left join bonus b on e.empId = b.empId where nvl(bonus,0) < 1000;