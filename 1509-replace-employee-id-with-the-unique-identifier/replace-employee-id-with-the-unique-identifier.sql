# Write your MySQL query statement below
SELECT e.name, enui.unique_id FROM Employees as e LEFT JOIN EmployeeUNI as enui ON e.id = enui.id;