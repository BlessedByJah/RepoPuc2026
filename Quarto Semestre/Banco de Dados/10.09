create table pedidos
(
codigo int auto_increment primary key,
codigo_cliente int not null,
data_pedido date not null,
total decimal(6,2) not null
);

create table clientes
(
codigo int auto_increment primary key,
nome varchar(50) not null,
celular char(14) not null,
email varchar(100) 
);

alter table pedidos
 add constraint FK_Clientes_Pedidos
 foreign key (codigo_cliente)
 references clientes(codigo);
insert into clientes
values
(4,'Samuel dos santos','(19)99263-9845','Samuel.santos@unisal.com'),
(5,'Ana garcia Ribeiro','(19)99136-8520','ana@outlook.com'),
(6,'Julia de Camargo','(19)99277-3693','ju.camargo@gmail.com');

insert into pedidos
values
(default,2,'2024-03-01',1500),
(default,3,'2024-03-01',900),
(default,2,'2024-03-02',2000),
(default,1,'2024-03-02',1300),
(default,2,'2024-03-03',850);

select clientes.nome, pedidos.data_pedido
from clientes join pedidos
on clientes.codigo = pedidos.codigo_cliente;

Select 
	c.codigo,
    c.nome,
    p.codigo AS pedido,
    p.data_pedido,
    p.total
FROM clientes c
LEFT JOIN pedidos p
On c.codigo = p.codigo_cliente;
==
SELECT 
	c.codigo,
    c.nome
FROM clientes c
LEFT JOIN pedidos p
		ON c.codigo = p.codigo_cliente
        WHERE p.codigo IS NULL;


ALTER TABLE pedidos
ADD CONSTRAINT chk_codigo_cliente
CHECK(codigo_cliente BETWEEN 1 AND 6);

alter table clientes
add sexo char(1) check (sexo IN ('M', 'F'));

UPDATE clientes
SET sexo = 'M'
WHERE codigo IN (1,4);

UPDATE clientes
SET sexo = 'F'
WHERE codigo IN (2,3,5,6);

UPDATE clientes
SET sexo = 'M'
WHERE codigo IN (1,4);

UPDATE clientes
SET sexo = 'F'
WHERE codigo IN (2,3,5,6);
