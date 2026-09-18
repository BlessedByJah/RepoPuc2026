create table Cliente (
id_cliente int not null primary key,
nome varchar(100),
cidade varchar(50)
)
create table  pedido
(
	id_pedido int not null primary key,
    data_pedido date,
    id_cliente int
)
create table item_pedido
(
id_item int not null primary key,
id_pedido int,
produto varchar(100),
quantidade int,
valor_unitario decimal(10,2)
)

insert into cliente (id_cliente, nome, cidade) values
(default, "Ana", "Campinas"),
(default, "Bruno", "Paulinia"),
(default, "Carlos", "Sumare"),
(default, "Daniela", "Campinas")

insert into pedido (id_pedido, data_pedido, id_cliente) values
(101, '2025-10-01', 1),
(102, '2025-10-02', 2),
(103, '2025-10-03', 1),
(104, '2025-10-05', 3),
(105, '2025-10-06', 4)


insert into item_pedido
(id_item,id_pedido,produto,quantidade,valor_unitario) values
(1	,101	,"Notebook",	1,	3500),
(2	,101	,"Mouse",	2,	50),
(3	,102	,"Monitor",	2,	1200),
(4	,103	,"Teclado",	3,	100),
(5	,103	,"Mouse",	1,	50),
(6	,104	,"Impressora",	1,	900),
(7	,105	,"Notebook",	2,	3500),
(8	,105	,"Mouse",	5,	50)

SELECT 
    id_pedido,
    produto,
    quantidade,
    valor_unitario,
    (quantidade * valor_unitario) AS valor_total_item
FROM item_pedido;

selct from]

SELECT 
    id_pedido,
    SUM(quantidade * valor_unitario) AS total_pedido
FROM item_pedido
GROUP BY id_pedido;

select 
    pedido.id_cliente,
    sum(item_pedido.quantidade * item_pedido.valor_unitario) 
AS total
FROM pedido 
INNER JOIN item_pedido ON pedido.id_pedido = item_pedido.id_pedido
GROUP BY pedido.id_cliente;

SELECT 
    p.id_cliente,
    SUM(i.quantidade * i.valor_unitario) AS total_gasto
FROM pedido p
INNER JOIN item_pedido i ON p.id_pedido = i.id_pedido
GROUP BY p.id_cliente
HAVING SUM(i.quantidade * i.valor_unitario) > 3000;

SELECT 
    produto,
    SUM(quantidade) 
    as TotalPedido
from 
	item_pedido
group by produto;

select 
    pedido.id_cliente,
    SUM(item_pedido.quantidade * item_pedido.valor_unitario) as total_gasto
from 
	pedido 
inner join 
	item_pedido 
on 
	pedido.id_pedido = item_pedido.id_pedido
group by
	pedido.id_cliente
having 
	sum(item_pedido.quantidade * item_pedido.valor_unitario) > 3000;
