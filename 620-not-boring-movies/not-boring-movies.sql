/* Write your PL/SQL query statement below */
select * from cinema where description != 'boring' and MOD(id,2) != 0 order by rating desc;