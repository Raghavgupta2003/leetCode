# Write your MySQL query statement below

SELECT EmployeeUNI.unique_id, Employees.name 
FROM Employees
LEFT OUTER JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id 

-- ess question mai bolaa hai ki humme saaaare names chaiye isliye hmne left join lgaaya
-- aur mention nhai jinki unique id nhi hai, wha null, toh humne id compare kr li.

