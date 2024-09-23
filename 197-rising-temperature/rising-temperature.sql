# Write your MySQL query statement below
-- t1 , t2
-- t1.recordDate + 1 = t2.recordDate
#where t1.temp < t2.temp


SELECT t2.id  FROM Weather AS t1 INNER JOIN Weather AS t2 
ON DATE_ADD(t1.recordDate, INTERVAL 1 DAY) = t2.recordDate
WHERE t1.temperature < t2.temperature
