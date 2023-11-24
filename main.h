#include "Menu.h"
#include "BDD.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int __clrcall WinMain(array<String^>^ args)
{
    try {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        BDD^ bdd = gcnew BDD();

        A2ProjetBloc2::Menu^ monFormulaire = gcnew A2ProjetBloc2::Menu(bdd);
        Application::Run(monFormulaire);
    }
    catch (Exception^ ex) {
        // Gérer l'exception ici (affichage de message d'erreur, journalisation, etc.)
        MessageBox::Show("Une exception s'est produite : " + ex->Message, "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

//pour moi t'as pas choisi le bon type de projet vu les dépendences
// et du coup je peux quand même créer un nouveau projet et tout 
// cle plus simple jpense mais jtest qd mm 1 truc