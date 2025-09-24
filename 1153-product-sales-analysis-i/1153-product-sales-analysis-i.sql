# Write your MySQL query statement below

-- jaise ki each sale id bolaa hai
-- Aur hmmari left wali table sales wali hai, iska matlab let outer join lagayege

SELECT P.product_name, S.year, S.price 
FROM Sales AS S
LEFT OUTER JOIN Product as P
ON 
S.product_id = P.product_id 