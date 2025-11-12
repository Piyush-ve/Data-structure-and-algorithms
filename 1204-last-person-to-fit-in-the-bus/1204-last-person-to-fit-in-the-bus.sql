# Write your MySQL query statement below
select q1.person_name
from Queue Q1 inner join Queue q2
on q1.turn >= q2.turn 
group by q1.turn
having sum(q2.weight) <= 1000
order by sum(q2.weight) desc
Limit 1;