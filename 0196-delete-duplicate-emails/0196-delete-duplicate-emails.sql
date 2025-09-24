# Write your MySQL query statement below

DELETE P1 FROM PERSON AS P1
INNER JOIN PERSON AS P2
WHERE P1.id > P2.id
AND
P1.email = P2.email

-- here we use the concept of self join
-- means applying inner join(for common) on both tables based on a condition.
