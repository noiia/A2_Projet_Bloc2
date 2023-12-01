#include "Menu.h"
#include "BDD.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int __clrcall WinMain(array<String^>^ args)
{
   // try {
        Application::EnableVisualStyles();
        Application::SetCompatibleTextRenderingDefault(false);
        BDD^ bdd = gcnew BDD();

        A2ProjetBloc2::Menu^ menuForm = gcnew A2ProjetBloc2::Menu(bdd);
        Application::Run(menuForm);
  //}
  //catch (Exception^ ex) {
  //    // Gérer l'exception ici (affichage de message d'erreur, journalisation, etc.)
  //    MessageBox::Show("Une exception s'est produite : " + ex->Message, "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
  //}
}