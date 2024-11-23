-- Write your PostgreSQL query statement below
SELECT * FROM Cinema WHERE NOT MOD(id,2) = 0 AND NOT description = 'boring' ORDER BY rating desc;