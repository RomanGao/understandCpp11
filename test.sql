
select * from
(
select table2.id, table2.work, a.age. a.name
from table2  
join
(select id, nnn as name, age 
from table1
where age < 60
)a
on table1.id = table2.id

having len(table2.work)>0
)