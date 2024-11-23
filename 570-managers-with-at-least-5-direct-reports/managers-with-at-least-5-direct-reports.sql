-- Write your PostgreSQL query statement below
SELECT m.name 
FROM Employee m 
LEFT JOIN Employee e 
ON e.managerId = m.id 
GROUP BY m.id, m.name 
HAVING COUNT(m.id) > 4;