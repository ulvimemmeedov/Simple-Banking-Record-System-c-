create table if not exists customer (

	id int unsigned auto_increment not null unique primary key,
	first_Name nvarchar(255) not null,
    last_Name nvarchar(255) not null,
    account_number int unsigned not null,
	balance decimal not null default 0,
	account_limit decimal not null default 100.0,
    tell nvarchar(255) not null

)engine=InnoDb charset=utf8;