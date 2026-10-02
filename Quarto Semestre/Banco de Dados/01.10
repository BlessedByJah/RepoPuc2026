Exercícios View
View de Obras com Exposição
{
CREATE OR REPLACE VIEW vw_obras_com_exposicao AS
SELECT o.id AS id_obra,
       o.titulo AS titulo_obra,
       e.titulo AS titulo_exposicao
FROM Obras o
JOIN Exposicoes e ON o.exposicao_id = e.id;

SELECT * FROM vw_obras_com_exposicao;
}

Mostra cada obra juntamente com a exposição onde está cadastrada.
{
CREATE OR REPLACE VIEW vw_obras_exposicoes_museus AS
SELECT o.id AS id_obra,
       o.titulo AS titulo_obra,
       o.data_aquisicao,
       e.titulo AS titulo_exposicao,
       e.tema,
       e.custo,
       m.nome AS nome_museu,
       m.cidade
FROM Obras o
JOIN Exposicoes e ON o.exposicao_id = e.id
JOIN Museus m ON e.museu_id = m.id;


SELECT * FROM vw_obras_exposicoes_museus;
}

View Completa de Obras, Exposições e Museus
{
CREATE OR REPLACE VIEW vw_qtd_obras_por_exposicao AS
SELECT e.id AS id_exposicao,
       e.titulo AS titulo_exposicao,
       COUNT(o.id) AS quantidade_obras
FROM Exposicoes e
LEFT JOIN Obras o ON o.exposicao_id = e.id
GROUP BY e.id, e.titulo;

SELECT * FROM vw_qtd_obras_por_exposicao ORDER BY quantidade_obras DESC;
}

View de Quantidade de Obras por Exposição
{
CREATE OR REPLACE VIEW vw_qtd_obras_por_exposicao AS
SELECT e.id AS id_exposicao,
       e.titulo AS titulo_exposicao,
       COUNT(o.id) AS quantidade_obras
FROM Exposicoes e
LEFT JOIN Obras o ON o.exposicao_id = e.id
GROUP BY e.id, e.titulo;

SELECT * FROM vw_qtd_obras_por_exposicao ORDER BY quantidade_obras DESC;
}

View de Quantidade de Obras por Museu
{
CREATE OR REPLACE VIEW vw_qtd_obras_por_museu AS
SELECT m.id AS id_museu,
       m.nome AS nome_museu,
       COUNT(o.id) AS quantidade_obras
FROM Museus m
LEFT JOIN Exposicoes e ON e.museu_id = m.id
LEFT JOIN Obras o ON o.exposicao_id = e.id
GROUP BY m.id, m.nome;

SELECT * FROM vw_qtd_obras_por_museu;
}

View de Custos das Exposições por Museu
{
CREATE OR REPLACE VIEW vw_custos_exposicoes_por_museu AS
SELECT m.id AS id_museu,
       m.nome AS nome_museu,
       COUNT(e.id) AS quantidade_exposicoes,
       SUM(e.custo) AS custo_total,
       AVG(e.custo) AS custo_medio,
       MAX(e.custo) AS maior_custo
FROM Museus m
LEFT JOIN Exposicoes e ON e.museu_id = m.id
GROUP BY m.id, m.nome;

SELECT * FROM vw_custos_exposicoes_por_museu ORDER BY custo_total DESC;
}
View de Obras sem Exposição Válida
{
CREATE OR REPLACE VIEW vw_obras_sem_exposicao_valida AS
SELECT o.id AS id_obra,
       o.titulo AS titulo_obra,
       o.exposicao_id
FROM Obras o
LEFT JOIN Exposicoes e ON o.exposicao_id = e.id
WHERE e.id IS NULL;

SELECT * FROM vw_obras_sem_exposicao_valida;
}
View de Exposições sem Obras
{
CREATE OR REPLACE VIEW vw_exposicoes_sem_obras AS
SELECT e.id AS id_exposicao,
       e.titulo AS titulo_exposicao,
       e.tema,
       e.custo
FROM Exposicoes e
LEFT JOIN Obras o ON o.exposicao_id = e.id
WHERE o.id IS NULL;

SELECT * FROM vw_exposicoes_sem_obras;
}
