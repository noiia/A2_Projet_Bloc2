USE [master]
GO


IF DB_ID('TurboStock') IS NOT NULL
DROP DATABASE TurboStock
GO

CREATE DATABASE TurboStock
GO

USE TurboStock
GO 

CREATE TABLE Adress(
   ID_Adress VARCHAR(50),
   number VARCHAR(50),
   addition VARCHAR(50),
   PRIMARY KEY(ID_Adress)
);
GO
CREATE TABLE postalCode(
   ID_PC VARCHAR(20),
   numberPC VARCHAR(50),
   PRIMARY KEY(ID_PC)
);

GO
CREATE TABLE City(
   INSEE_Code VARCHAR(50),
   name VARCHAR(50),
   ID_PC VARCHAR(20) NOT NULL,
   PRIMARY KEY(INSEE_Code),
   FOREIGN KEY(ID_PC) REFERENCES postalCode(ID_PC)
);
GO
CREATE TABLE Staff(
   ID_staff VARCHAR(50),
   firstName VARCHAR(50),
   name VARCHAR(50),
   supH VARCHAR(50),
   dateTakingPoste DATE,
   PRIMARY KEY(ID_staff)
);
GO
CREATE TABLE Customer(
   ID_customer VARCHAR(50),
   firstName VARCHAR(50),
   name VARCHAR(50),
   PRIMARY KEY(ID_customer)
);
GO
CREATE TABLE Ordering(
   ID_Ordering VARCHAR(50),
   orderingDate DATE,
   PRIMARY KEY(ID_Ordering)
);
GO
CREATE TABLE Payment(
   ID_payment VARCHAR(50),
   issueDate DATE,
   paymentDate DATE,
   paymentDivision INT,
   paymentStatus BIT,
   paymentState CHAR(1),
   paymentType VARCHAR(50),
   price DECIMAL(15,2),
   PRIMARY KEY(ID_payment)
);
GO
CREATE TABLE Individual(
   ID_Individual VARCHAR(50),
   birthday DATE,
   firstBuyDate DATE,
   ID_customer VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Individual),
   UNIQUE(ID_customer),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer)
);
GO
CREATE TABLE Storage(
   reference VARCHAR(50),
   quantity BIGINT,
   restockingTreshold DATE,
   PRIMARY KEY(reference)
);
GO
CREATE TABLE Compagny(
   ID_Compagny VARCHAR(50),
   serviceNumber CHAR(10),
   logo image,
   ID_customer VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_Compagny),
   UNIQUE(ID_customer),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer)
);
GO
CREATE TABLE Article(
   ID_article VARCHAR(50),
   designation VARCHAR(50),
   priceBeforeTaxes DECIMAL(15,2),
   taxesPourcentile DECIMAL(15,2),
   taxesValue DECIMAL(15,2),
   priceWithTaxes DECIMAL(15,2),
   PRIMARY KEY(ID_article)
);
GO
CREATE TABLE Street(
   ID_street VARCHAR(50),
   nameStreet VARCHAR(50),
   INSEE_Code VARCHAR(50) NOT NULL,
   PRIMARY KEY(ID_street),
   FOREIGN KEY(INSEE_Code) REFERENCES City(INSEE_Code)
);
GO
CREATE TABLE Invoice(
   ID_Adress VARCHAR(50),
   ID_customer VARCHAR(50),
   ID_Ordering VARCHAR(50),
   PRIMARY KEY(ID_Adress, ID_customer, ID_Ordering),
   FOREIGN KEY(ID_Adress) REFERENCES Adress(ID_Adress),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer),
   FOREIGN KEY(ID_Ordering) REFERENCES Ordering(ID_Ordering)
);
GO
CREATE TABLE Delivery(
   ID_Adress VARCHAR(50),
   ID_customer VARCHAR(50),
   ID_Ordering VARCHAR(50),
   PRIMARY KEY(ID_Adress, ID_customer, ID_Ordering),
   FOREIGN KEY(ID_Adress) REFERENCES Adress(ID_Adress),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer),
   FOREIGN KEY(ID_Ordering) REFERENCES Ordering(ID_Ordering)
);
GO
CREATE TABLE Home(
   ID_Adress VARCHAR(50),
   ID_staff VARCHAR(50),
   ID_customer VARCHAR(50),
   PRIMARY KEY(ID_Adress, ID_staff, ID_customer),
   FOREIGN KEY(ID_Adress) REFERENCES Adress(ID_Adress),
   FOREIGN KEY(ID_staff) REFERENCES Staff(ID_staff),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer)
);
GO
CREATE TABLE compose(
   ID_Adress VARCHAR(50),
   INSEE_Code VARCHAR(50),
   PRIMARY KEY(ID_Adress, INSEE_Code),
   FOREIGN KEY(ID_Adress) REFERENCES Adress(ID_Adress),
   FOREIGN KEY(INSEE_Code) REFERENCES City(INSEE_Code)
);
GO
CREATE TABLE contain(
   ID_street VARCHAR(50),
   ID_Adress VARCHAR(50),
   PRIMARY KEY(ID_street, ID_Adress),
   FOREIGN KEY(ID_street) REFERENCES Street(ID_street),
   FOREIGN KEY(ID_Adress) REFERENCES Adress(ID_Adress)
);
GO
CREATE TABLE regroup(
   ID_Ordering VARCHAR(50),
   ID_article VARCHAR(50),
   PRIMARY KEY(ID_Ordering, ID_article),
   FOREIGN KEY(ID_Ordering) REFERENCES Ordering(ID_Ordering),
   FOREIGN KEY(ID_article) REFERENCES Article(ID_article)
);
GO
CREATE TABLE pay(
   ID_customer VARCHAR(50),
   ID_payment VARCHAR(50),
   PRIMARY KEY(ID_customer, ID_payment),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer),
   FOREIGN KEY(ID_payment) REFERENCES Payment(ID_payment)
);
GO
CREATE TABLE buy(
   ID_customer VARCHAR(50),
   ID_article VARCHAR(50),
   PRIMARY KEY(ID_customer, ID_article),
   FOREIGN KEY(ID_customer) REFERENCES Customer(ID_customer),
   FOREIGN KEY(ID_article) REFERENCES Article(ID_article)
);
GO
CREATE TABLE include(
   ID_Ordering VARCHAR(50),
   ID_payment VARCHAR(50),
   PRIMARY KEY(ID_Ordering, ID_payment),
   FOREIGN KEY(ID_Ordering) REFERENCES Ordering(ID_Ordering),
   FOREIGN KEY(ID_payment) REFERENCES Payment(ID_payment)
);
GO
CREATE TABLE access(
   ID_staff VARCHAR(50),
   reference VARCHAR(50),
   PRIMARY KEY(ID_staff, reference),
   FOREIGN KEY(ID_staff) REFERENCES Staff(ID_staff),
   FOREIGN KEY(reference) REFERENCES Storage(reference)
);
GO

CREATE TABLE stock(
   reference VARCHAR(50),
   ID_article VARCHAR(50),
   PRIMARY KEY(reference, ID_article),
   FOREIGN KEY(reference) REFERENCES Storage(reference),
   FOREIGN KEY(ID_article) REFERENCES Article(ID_article)
);
GO