create table Museus (
id int primary key,
nome varchar(120) not null,
cidade VARCHAR(80),
ano_inaugurado int );


create table Exposicoes 
(
id int primary key,
titulo varchar(150) not null,
tema varchar(200),
custo decimal(12,2),
museu_id int,
foreign key (museu_id) references Museus(id)
);

create table Obras 
(
 id int primary key,
 titulo varchar(120) not null,
 data_aquisicao date,
 exposicao_id int,
 foreign key (exposicao_id) references Exposicoes(id)
);

insert into Museus (id,nome,cidade,ano_inaugurado) values
(1, 'MASP', 'São Paulo', 1947),
(2,'Museu Nacional de belas Artes', 'Rio de Janeiro', 1937),
(3,'Museu Oscar Niemeyer','Curitiba',2002);

insert into Exposicoes 
(id,titulo,tema,custo,museu_id)
values
(1,'Arte Brasileira Moderna', 'Arte Moderna', 15000.00, 1),
(2,'Esculturas Classicas', 'Escultura', 12000.00, 1),
(3,'Arte Renascentista', 'art eruopeia', 18000.00, 2),
(4,'Design contemporaneo', 'design e arte', 8000.00, 3),
(5,'Fotografia Brasileira', 'fotografia', 4500.00, 3),
(6,'Arte Digital', 'arte tecnologia', 20000.00, 3);

insert into Obras
Values

(1,'Abaporu','2019-03-10',1),
(2,'Operarios','2020-08-15',1),
(3,'David Replica','1945-05-20',2),
(4,'Mona Lisa Copia','1980-07-30',3),
(5,'Luzes Urbanas','2022-11-11',4),
(6,'retratos do brasil','2017-09-18',5),
(7,'Arte Generativa IA','2024-02-25',6),
(8,'Paisagem Colonial','1930-06-14',3);

alter table Museus ADD Column orcamento decimal(15,2);
alter table Exposicoes modify custo decimal(15,2);

////set SQL_safe_updates = 0 ;

update Museus
Set orcamento =
 case id
		when 1 then 1500000.00
        when 2 then 1200000.00
        when 3 then 10000000.00
        end;

select m.nome as nome_museu,
count(e.id) as quantidade_exposicoes
from Museus m
Join Exposicoes e 
ON m.id = e.museu_id
group By m.id, m.nome
having count(e.id) > 1;

(select nome FROM Museus
Where ano_inaugurado < 1950
order by ano_inaugurado Limit 10)
Union
(select titulo
from Exposicoes
where tema like '%arte%');

Select m.nome,
max(e.custo) as maior_custo
from Museus m
Join Exposicoes e 
ON m.id = e.Museu_id
group by m.id, m.nome
order by maior_custo desc;

select o.titulo as titulo_obra, e.titulo as titulo_exposicao,

Case
	when o.data_aquisicao < '1950-01-01' then 'antiga'
    when o.data_aquisicao between '1950-01-01' and 
		'1999-12-31' then 'Moderna'
        
        when o.data_aquisicao >= '2000-01-01' then 'Contemporânea'
        end as classificacao
        from Obras o join Exposicoes e ON o.exposicao_id = e.id;
    

delete from Exposicoes 
where custo < 5000 and museu_id IN
(
	select id from Museus where ano_inaugurado > 2000
);


select o.titulo AS titulo_obra,
e.titulo as titulo_exposicao,
e.custo AS valor_exposicao
from Obras o
Join Exposicoes e 
ON o.exposicao_id = e.id
ORDER by e.custo desc limit  3;
