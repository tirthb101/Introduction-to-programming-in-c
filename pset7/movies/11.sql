SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = "Chadwick Boseman")) ORDER BY (SELECT rating FROM ratings where movie_id = id) DESC LIMIT 5;