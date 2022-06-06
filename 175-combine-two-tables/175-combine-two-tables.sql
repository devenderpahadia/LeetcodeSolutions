# Write your MySQL query statement below

select Firstname,Lastname,City,State
from Person left join Address 
on Person.PersonId = Address.PersonId;
