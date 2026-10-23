create table clientes (
codigo int auto_increment PRIMARY KEY,
nome  VARCHAR(100) NOT NULL,
celular  VARCHAR(100),
email varchar(50),
sexo char(1)) ;

insert into clientes (nome,celular,email,sexo)
values
('Samuel dos santos', '(19)992639845', 'samuel@gmail.com','M'),
('Ana garcia Ribeiro', '(19)991368520', 'anagarcia@gmail.com','F'),
('Julia de Camargo', '(19)992773693', 'julia@gmail.com','F');

create table pedidos ( 
codigo int auto_increment primary key,
codigo_cliente int,
codigo_fornecedor int,
data_pedido date,
total decimal(6,2));

insert into pedidos 
(codigo_cliente,codigo_fornecedor,data_pedido,total)
values
(2,1,'2024-03-01',1500),
(3,2,'2024-03-01',900),
(2,1,'2024-03-02',2000),
(1,3,'2024-03-02',1300),
(2,1,'2024-03-03',850);

alter table pedidos 
add constraint fk_fornecedor_pedidos
foreign key (codigo_fornecedor)
references fornecedores(codigo);

alter table pedidos
add constraint fk_cliente_pedidos
foreign key (codigo_cliente)
references clientes(codigo);

alter table pedidos
add constraint fk_fornecedor_pedidos
foreign key (codigo_fornecedor)
references fornecedores(codigo)
on delete cascade;

select * from pedidos
where codigo_fornecedor = 1;	

create table usuarios (codigo int primary key ,
nome varchar (50));

create table listas ( 
codigo int primary key,
nome varchar(50),
codigo_usuario int,
foreign key (codigo_usuario)
references usuarios(codigo)
on delete cascade );

create table itens_lista (
codigo int primary key,
titulo varchar(100),
codigo_lista int ,
foreign key (codigo_lista)
references listas(codigo)
on delete cascade);

insert into usuarios values 
(1, 'Ana'),
(2,'Carlos');

insert into listas values 
(10, 'Filmes para o fim de semana', 1),
(11, 'Minhas séries favoritas',1),
(12,'Filmes de ação',2);

insert into itens_lista values 
(100,'Interestelar',10),
(101,'oppenheimer',10),
(102,'Stranger Things',11),
(103,'Breaking Bad', 11),
(104, 'John Wick',12);

delete from  usuarios where codigo = 1;
