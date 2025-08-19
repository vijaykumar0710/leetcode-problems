select *,
IF(x+y>z && y+z>x && x+z>y,"Yes","No") as triangle
from Triangle 