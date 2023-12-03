#include "BDD.h"

using namespace System;
using namespace System::Data::SqlClient;
// Test
BDD::BDD()
{
    try
    {
        // Chaine de connexion
        String^ connectString = "Data Source=127.0.0.1,1433;Initial Catalog = TurboStock ;User ID=sa;Password=Test$Test1";
        // Objet connection
        connection = gcnew SqlConnection(connectString);
        // Ouverture
        connection->Open();
        System::Diagnostics::Debug::WriteLine("Connexion ok");
    }
    catch (Exception^ ex)
    {
        System::Diagnostics::Debug::WriteLine(ex->ToString());
    }
}

BDD::~BDD()
{

}
System::Data::DataSet^ BDD::executeQuery(String^ sql)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlDataAdapter^ da = gcnew SqlDataAdapter(sql, this->connection);
    // Cr�ation d'un DataSet
    System::Data::DataSet^ ds = gcnew System::Data::DataSet();
    // Remplissage du DataSet avec le SqlDataAdapter
    da->Fill(ds);

    return ds;
}

int BDD::executeNonQuery(String^ sql)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlCommand^ command = gcnew SqlCommand(sql, this->connection);
    // Execution
    int affectedrows = command->ExecuteNonQuery();
    return affectedrows;
}

int BDD::executeInsert(String^ sql, bool geneID)
{
    System::Diagnostics::Debug::WriteLine("REQSQL: " + sql);
    SqlCommand^ command = gcnew SqlCommand(sql + ";SELECT @@IDENTITY", this->connection);
    // Execution
    if (geneID) {
        try {
            Object^ result = command->ExecuteScalar();
            if (result != nullptr) {
                return Convert::ToInt32(result);

                try {
                    return Convert::ToInt32(result);
                }
                catch (InvalidCastException^) {
                    System::Diagnostics::Debug::WriteLine("La conversion en int a échoué.");
                    return -1;
                }
            }
            else {
                System::Diagnostics::Debug::WriteLine("Le résultat est null.");
                return -1;
            }

        }
        catch (Exception^ ex) {
            System::Diagnostics::Debug::WriteLine("Erreur lors de l'exécution de la requête : " + ex->Message);
            return -1;
        }
    }
    else {
        return 0;
    }
}