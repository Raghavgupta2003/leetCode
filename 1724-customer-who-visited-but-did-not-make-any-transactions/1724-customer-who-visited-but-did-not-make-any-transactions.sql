# Write your MySQL query statement below

SELECT V.customer_id, COUNT(*) AS count_no_trans
FROM Visits AS V
LEFT OUTER JOIN Transactions AS T
ON V.visit_id = T.visit_id
WHERE T.transaction_id IS NULL
GROUP BY V.customer_id

-- esme sun hume kyaa krna hai ki
-- visits toh saare dekhne hai, aur jin visits mai trnsaction nhi hue unhe null mark krna hai
-- islie left join lgaya
-- bina transaction wale nikalne k liye humne where mai condition daal thi
-- group ka use kiya grouping k liye