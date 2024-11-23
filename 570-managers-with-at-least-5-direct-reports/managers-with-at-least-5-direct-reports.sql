-- Write your PostgreSQL query statement below
SELECT m.name from Employee e JOIN Employee m ON e.managerId = m.id GROUP BY e.managerId, m.name HAVING COUNT(e.managerId) > 4;