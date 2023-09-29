# DELETE
# FROM Person
# WHERE id NOT IN (
#     SELECT MIN(id)
#     FROM Person
#     GROUP BY email
#     HAVING count(email) > 1
# )
# DELETE p1
# FROM Person p1
# JOIN (
#     SELECT MIN(id) AS min_id, email
#     FROM Person
#     GROUP BY email
#     HAVING COUNT(email) > 1
# ) p2
# ON p1.email = p2.email
# AND p1.id > p2.min_id;

DELETE p1 
FROM Person p1, Person p2
WHERE p1.email = p2.email AND p1.id > p2.id;
