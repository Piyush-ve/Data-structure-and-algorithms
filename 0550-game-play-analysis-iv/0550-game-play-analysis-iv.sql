# Write your MySQL query statement below
select round(count(distinct player_id)/ (select count(distinct player_id) from Activity), 2) as fraction
from activity
where (player_id, DAte_sub(event_date, Interval 1 day)) in(
    select player_id, Min(event_date) as first_login 
    from activity
    group by player_id
)


