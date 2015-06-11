-- db2 -td@ -vf test.db2
connect to perf_dev user ihchung_admin using 'viral=498penh'@

list tables@

 drop table hpc_run@


create table hpc_run (
     hpc_run_id int not null primary key generated always as identity,
     hpc_run_date timestamp not null,
     job_id int not null,
     hpc_session_id int
)@

describe table hpc_run@

 drop variable runid@
 create variable runid integer@


select application_id()  from sysibm.sysdummy1@

-- begin atomic
-- declare ssid int;
insert into hpc_run (hpc_run_id, hpc_run_date,job_id, hpc_session_id) values(default, current_timestamp,1,2)@

--select * from hpc_run@

 insert into hpc_run (hpc_run_id, hpc_run_date,job_id, hpc_session_id) values(default, current_timestamp,3,4)@


set runid=(select job_id from final table (insert into hpc_run (hpc_run_id, hpc_run_date,job_id, hpc_session_id) values(default, current_timestamp,7,8)))@



values runid@



begin 
declare sssid int;
declare target int;
set sssid = (select hpc_run_id from final table ( insert into hpc_run (hpc_run_id, hpc_run_date,job_id, hpc_session_id) values(default, current_timestamp,5,6))  order by hpc_run_id desc fetch first 1 rows only);

set target=5;

set sssid=(select count(*) from hpc_run where job_id=target);


if (sssid = 0) 
then set sssid=(select job_id from final table (insert into hpc_run (hpc_run_id, hpc_run_date,job_id, hpc_session_id) values(default, current_timestamp,7,8)));
else
 set sssid=(select job_id from hpc_run where job_id=target);
end if;


set runid = sssid;
end  @

values runid@

-- end@
--  set ssid=(select hpc_run_id from hpc_run order by hpc_run_id desc fetch first 1 rows only);
