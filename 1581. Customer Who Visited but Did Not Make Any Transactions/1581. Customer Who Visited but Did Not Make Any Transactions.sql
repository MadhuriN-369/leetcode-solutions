1select customer_id , count(visit_id) as count_no_trans from visits
2where visit_id not in (select visit_id from transactions)
3group by customer_id;