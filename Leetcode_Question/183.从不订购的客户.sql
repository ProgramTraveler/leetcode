--
-- @lc app=leetcode.cn id=183 lang=mysql
--
-- [183] 从不订购的客户
--

-- @lc code=start
select customers.name as 'Customers'
from customers
where customers.id not in
(
    select customerid from orders
);
-- @lc code=end

