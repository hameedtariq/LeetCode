-- Write your PostgreSQL query statement below
SELECT ei.unique_id, e.name 
FROM Employees e 
LEFT JOIN EmployeeUNI ei 
ON e.id = ei.id;