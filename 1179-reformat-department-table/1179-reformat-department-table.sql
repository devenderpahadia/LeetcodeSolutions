# Write your MySQL query statement below

SELECT ID,
    SUM(CASE WHEN MONTH='Jan' THEN REVENUE END) AS JAN_REVENUE,
    SUM(CASE WHEN MONTH='Feb' THEN REVENUE END) AS Feb_REVENUE,
    SUM(CASE WHEN MONTH='Mar' THEN REVENUE END) AS Mar_REVENUE,
    SUM(CASE WHEN MONTH='Apr' THEN REVENUE END) AS Apr_REVENUE,
    SUM(CASE WHEN MONTH='May' THEN REVENUE END) AS May_REVENUE,
    SUM(CASE WHEN MONTH='Jun' THEN REVENUE END) AS Jun_REVENUE,
    SUM(CASE WHEN MONTH='Jul' THEN REVENUE END) AS Jul_REVENUE,
    SUM(CASE WHEN MONTH='Aug' THEN REVENUE END) AS Aug_REVENUE,
    SUM(CASE WHEN MONTH='Sep' THEN REVENUE END) AS Sep_REVENUE,
    SUM(CASE WHEN MONTH='Oct' THEN REVENUE END) AS Oct_REVENUE,
    SUM(CASE WHEN MONTH='Nov' THEN REVENUE END) AS Nov_REVENUE,
    SUM(CASE WHEN MONTH='Dec' THEN REVENUE END) AS Dec_REVENUE
FROM DEPARTMENT
Group by id;
        
