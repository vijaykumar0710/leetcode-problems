select 
    CASE 
       WHEN
          id=(select MAX(id) from Seat) && MOD(id,2)=1
          THEN id
          WHEN 
          MOD(id,2)=1
            THEN id+1
         else
         id-1
    END AS id,student
    from Seat
    ORDER BY id