# Write your MySQL query statement below
select 
"Low Salary" as Category,
Count(income) as accounts_count
from Accounts
where income< 20000

UNION 

select 
"Average Salary" as Category,
Count(income) as accounts_count
from Accounts
where income >= 20000 AND income <= 50000

UNION 

select 
"High Salary" as Category,
Count(income) as accounts_count
from Accounts
where income> 50000;

