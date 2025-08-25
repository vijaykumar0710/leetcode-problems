(
    select name as results
    from Users
    inner join MovieRating USING(user_id)
    group by user_id
    order by COUNT(rating) DESC,name
    limit 1
)
UNION ALL
(
    select title as results
    from Movies
    inner join MovieRating USING(movie_id)
    where month(created_at)='02' AND YEAR(created_at)='2020'
    group by title
    order by AVG(rating) DESC,title
    limit 1
)