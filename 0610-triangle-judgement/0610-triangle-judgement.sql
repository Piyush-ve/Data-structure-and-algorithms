# Write your MySQL query statement below
select * , 
if(x+y>z And y+z>x AND z+x>y, "Yes", "No") as triangle 
from Triangle;
