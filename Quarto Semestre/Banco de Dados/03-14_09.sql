create table fornecedores
(codigo int not null auto_increment primary key,
nome varchar(50) not null);

insert into fornecedores
values
(default, 'hp'),
(default, 'dell'),
(default, 'cisco');

truncate table pedidos;

alter table pedidos
add column codigo_fornecedor int not null after codigo_cliente;

INSERT INTO pedidos (codigo_cliente, codigo_fornecedor, data_pedido, total)
VALUES
(2, 1, '2024-03-01', 1500),
(3, 2, '2024-03-01', 900),
(2, 1, '2024-03-02', 2000),
(1, 3, '2024-03-02', 1300),
(2, 1, '2024-03-03', 850); 


=== 

select f.nome,
	p.data_pedido,
    p.total
FROM fornecedores f
LEFT JOIN pedidos p
ON f.codigo = p.codigo_fornecedor;

==

SELECT c.nome,
	COUNT(p.codigo) AS Quantidade_Pedidos
    FROM clientes c
    LEFT JOIN pedidos p
    ON c.codigo = p.codigo_cliente
    GROUP BY c.nome;

==

select c.nome as cliente,
f.nome as fornecedor,
p.total

from pedidos p
inner join clientes c
on p.codigo_cliente = c.codigo
inner join fornecedores f
on p.codigo_fornecedor = f.codigo;

==

select f.nome as fornecedor,
sum(p.total) AS faturamento

from fornecedores f
inner join pedidos p
on f.codigo = p.codigo_fornecedor
group by f.nome
having sum(p.total) = (
select max(FATURAMENTO)
FROM (
		select sum(total) AS faturamento
        from pedidos
        group by codigo_fornecedor
	 )AS dados
);
