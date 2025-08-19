select 
"Low Salary" as category,
COUNT(income) as accounts_count 
from Accounts 
where income <20000
UNION
select 
"Average Salary" as category,
COUNT(income) as accounts_count 
from Accounts
where income >=20000 && income<=50000
UNION
select 
"High Salary" as category,
COUNT(income) as accounts_count 
from Accounts
where income >50000