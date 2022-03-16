# Write your MySQL query statement below
SELECT e.name as 'Employee'
from Employee e
where e.Salary > (Select d.salary from Employee d where e.managerId = d.id);