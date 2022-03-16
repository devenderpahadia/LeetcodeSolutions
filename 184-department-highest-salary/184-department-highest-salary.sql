# Write your MySQL query statement below

Select  Department.name as 'Department',
        Employee.name as 'Employee',
        Salary
from
        Employee
        join
        department on Employee.DepartmentId = Department.Id
where
       (Employee.DepartmentId ,Salary) in
       (select DepartmentId,max(Salary)
        from Employee
        group by DepartmentId
       )
       ;
       
