INSERT INTO amigo VALUES (123, 'Lopez', 'Garcia', 'Odera', 'Av. Del Pozo No. 17'); 
INSERT INTO amigo VALUES (125, 'Diaz', 'Reyes', 'Gonzalo', 'Av. Del Pozo No. 14'); 
INSERT INTO amigo VALUES (127, 'Cardona', 'Reyes', 'Renato', 'Av. Del Pozo No. 71');

INSERT INTO TRABAJADOR VALUES (11,123456,'RUMR930611','Gutierrez','Seis','Yesenia',30000,'2005/08/21','1988/07/28');
INSERT INTO telefono VALUES (default, 123, 151515);
INSERT INTO telefono VALUES (default, 123, 171717);
INSERT INTO telefono VALUES (default, 125, 313131);
INSERT INTO telefono VALUES (default, 125, 323232);

SELECT tel FROM amigo, telefono 
WHERE NomPila LIKE 'Odera' AND amigo.cve = telefono.cve;

INSERT INTO Amigo VALUES (123, 'Lopez', 'Garcia', 'Odera', 'Av. Del Pozo No. 17'); 
INSERT INTO Amigo VALUES (1000, 'Cortes', 'Duarte', 'Jose Luis', 'Av. Del Pozo No. 17', '1994/11/11' 
); 

INSERT INTO amigo (Cve, ApPat, NomPila, Dir) VALUES (130, 'Ruiz', 'Ricardo', 'Calle de las Fogatas No. 55');

UPDATE Amigo 
SET Cve = 456
WHERE Cve = 123;

UPDATE Amigo 
SET Colonia = 'Villa Nicolas Romero'
WHERE Cve = 125;

UPDATE Amigo 
SET Colonia = 'San Mateo'
WHERE Cve = 130;

SELECT Tel FROM Amigo, Telefono 
WHERE NomPila LIKE 'Gonzalo' AND Amigo.cve = Telefono.cve; 

ALTER TABLE MATERIA 
ADD COLUMN NomMateria VARCHAR (25) AFTER IdMateria;

LOAD DATA LOCAL INFILE 'C:/xampp/mysql/data/Alumno/AlumnEdad.txt' INTO TABLE EdadPrueba FIELDS TERMINATED 
BY '	' LINES TERMINATED BY '\n';
 
LOAD DATA LOCAL INFILE 'C:/Users/MrRubik/Dropbox/Bases/Practica3/Deleg.txt' INTO TABLE DELEGACION FIELDS TERMINATED 
BY ',' LINES TERMINATED BY '\n';

LOAD DATA LOCAL INFILE 'C:/Users/MrRubik/Dropbox/Bases/Practica3/nombres.txt' INTO TABLE ALUMNO FIELDS TERMINATED 
BY ',' LINES TERMINATED BY '\n';


CREATE VIEW agendatel.mivista AS 
SELECT idAmigo, ApPat, ApMat, NomPila, 
(YEAR(CURDATE())-YEAR(FechaNac)) 
- (MONTH(CURDATE()) < MONTH(FechaNac)) AS Edad 
FROM Amigo; 
 
SHOW TABLES; 
DESCRIBE mivista;

CREATE VIEW Alumno.AlumnEdad AS 
SELECT ALUMNO.CveAlu, ApPat, ApMat, NomPila, Tel 
FROM Amigo, Telefono 
WHERE Amigo.idAmigo = Telefono.AMIGO_idAmigo;

SELECT idAmigo, ApPat, ApMat, NomPila, Edad 
FROM mivista 
WHERE Edad >= 18; 

CREATE VIEW Alumno.AlumnEdad AS
SELECT CveAlu, ApPat, ApMat, NomPila,
(YEAR(CURDATE())-YEAR(FechaNac))
- (MONTH(CURDATE()) < MONTH(FechaNac)) AS Edad 
FROM ALUMNO; 
 
SHOW TABLES; 
DESCRIBE mivista; 
SELECT * FROM mivista;

SELECT CONCAT_WS(',', CveAlu, ApPat, ApMat, NomPila, Edad, '\n') FROM AlumnEdad;

CREATE TABLE EdadPrueba (
CveEdadP INT NOT NULL PRIMARY KEY,
ApPat VARCHAR (30),
ApMat VARCHAR (30),
Edad INT
) ENGINE=InnoDB;

DELETE FROM TRABAJADOR
WHERE NumTrabajador = 10;

DELETE FROM TRABAJADOR
WHERE NumTrabajador = 11;

INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (1,"305","CY34083922050772511517197410","Madison","Page","Drake",7128,"2008/03/20","1985/11/12");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (2,"939","SK5620847549297620362483","Madeson","Griffith","Griffin",6810,"2001/02/23","1952/03/25");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (3,"209","KW7081826014002788482878670150","Brielle","Webb","Herman",6147,"2005/02/23","1978/12/27");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (4,"901","HU53431482742414616234749977","Eleanor","Maddox","Dodson",6039,"2006/07/14","1977/11/08");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (5,"935","SK9584619518098134675194","Hedy","Lara","Simpson",7053,"2004/06/28","1983/10/10");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (6,"410","SK6757164952850133348695","John","Marquez","West",6667,"2002/02/12","1975/08/25");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (7,"314","MD5918780168639676742646","Shad","Gamble","Estrada",7755,"2005/03/12","1989/06/21");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (8,"325","MD6388820401534510535685","Declan","Parrish","Davis",9980,"2007/11/25","1981/06/26");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (9,"188","BG36XAFJ71252007687378","Tamara","Bradley","Shaw",7541,"2009/06/10","1957/08/27");
INSERT INTO `TRABAJADOR` (`NumTrabajador`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`Sueldo`,`FechaIngreso`,`FechaNac`) VALUES (10,"274","IT492SELLI88964454473607668","Tashya","Peters","Watts",9497,"2010/01/16","1980/12/14");

INSERT INTO PROFESOR VALUES (1,"2007/11/25");
INSERT INTO PROFESOR VALUES (2,"2009/06/10");
INSERT INTO PROFESOR VALUES (3,"2010/01/16");
INSERT INTO PROFESOR VALUES (5,"1983/10/10");

INSERT INTO ESPACIOS VALUES (1,30,4);
INSERT INTO ESPACIOS VALUES (2,30,4);
INSERT INTO ESPACIOS VALUES (3,30,6);

INSERT INTO PERS_LIMPIEZA VALUES (4);
INSERT INTO PERS_LIMPIEZA VALUES (6);

INSERT INTO CONSEJERO VALUES (7,5);
INSERT INTO CONSEJERO VALUES (8,10);

INSERT INTO MODERADOR VALUES (9);
INSERT INTO MODERADOR VALUES (10);

INSERT INTO `ESTUDIANTE` (`NumBoleta`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`FechaNac`) VALUES (8,"325","MD6388820401534510535685","Declan","Parrish","Davis","1981/06/26");
INSERT INTO `ESTUDIANTE` (`NumBoleta`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`FechaNac`) VALUES (9,"188","BG36XAFJ71252007687378","Tamara","Bradley","Shaw","1957/08/27");
INSERT INTO `ESTUDIANTE` (`NumBoleta`,`NumSS`,`CURP`,`NombrePila`,`ApellidoP`,`ApellidoM`,`FechaNac`) VALUES (10,"274","IT492SELLI88964454473607668","Tashya","Peters","Watts","1980/12/14");

INSERT INTO MEDIOS_SALON VALUES (1,'proyector');
INSERT INTO MEDIOS_SALON VALUES (1,'grabadora');
INSERT INTO MEDIOS_SALON VALUES (2,'proyector');
INSERT INTO MEDIOS_SALON VALUES (3,'proyector');

INSERT INTO SALON VALUES (1);
INSERT INTO LABORATORIO VALUES (2,10);
INSERT INTO SALA_ESP VALUES (3);

INSERT INTO EVENTO VALUES (1, '2014/05/29', '2014/05/29 12:00:00', 3);
INSERT INTO EVENTO VALUES (2, '2014/05/29', '2014/05/29 13:00:00', 3);

INSERT INTO MATERIAL VALUES (1, 'CABLES', 100, 2);
INSERT INTO MATERIAL VALUES (2, 'MULTIMETROS', 5, 2);

INSERT INTO MATERIA VALUES (2CM5,'Bases de datos',1);
INSERT INTO MATERIA VALUES (2CM3,'Redes de computadoras',2);

INSERT INTO CLUB VALUES (1, '2000/06/01', 'CLUB DE CINE', 9);
INSERT INTO CLUB VALUES (2, '2003/09/01', 'CLUB DE TEATRO', 10);

INSERT INTO CLUB_RECON VALUES (1, 'PREMIO AL MEJOR CORTO','2003/08/01');
INSERT INTO CLUB_RECON VALUES (2, 'PREMIO A LA MEJOR OBRA','2006/09/01');






