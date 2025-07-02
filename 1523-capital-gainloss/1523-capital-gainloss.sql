select s.stock_name,SUM(IF(s.operation='Buy',-s.price,s.price)) as capital_gain_loss 
from Stocks s
group by stock_name;