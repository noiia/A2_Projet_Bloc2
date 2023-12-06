//#pragma once
//#include <Windows.h>
//#include "Client.h"
//#include "Address.h"
//
//namespace A2ProjetBloc2 {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// Description résumée de ClientDetails
//	/// </summary>
//	public ref class ClientDetails : public System::Windows::Forms::Form
//	{
//		Client^ client;
//		Address^ address;
//		Label^ lblIdClient;
//		Label^ lblFirstName;
//		Label^ lblLastName;
//		Label^ lblBirthDay;
//		Label^ lblTypeClient;
//
//	private: System::Windows::Forms::Label^ LbProfilDetails;
//			 System::Windows::Forms::Label^ LbFirstName;
//			 System::Windows::Forms::Label^ LbBirthDay;
//			 System::Windows::Forms::Label^ LbLastName;
//			 System::Windows::Forms::Label^ LbTypeClient;
//			 System::Windows::Forms::Label^ LbInfosClient;
//			 System::Windows::Forms::Label^ LbBillingAddress;
//			 System::Windows::Forms::Label^ LbNumeroBilling;
//			 System::Windows::Forms::Label^ LbStreetBilling;
//			 System::Windows::Forms::Label^ LbPostalCodeBilling;
//			 System::Windows::Forms::Label^ LbCityBilling;
//			 System::Windows::Forms::Label^ LbAdditionBilling;
//			 System::Windows::Forms::Label^ LbDeliveryAdress;
//			 System::Windows::Forms::Label^ LbNumeroDelivery;
//			 System::Windows::Forms::Label^ LbStreetDelivery;
//			 System::Windows::Forms::Label^ LbAdditionDelivery;
//			 System::Windows::Forms::Label^ LbPostalCodeDelivery;
//			 System::Windows::Forms::Label^ LbCityDelivery;
//	public:
//		ClientDetails(Client^ client) : client(client)
//		{
//			InitializeComponent();
//			LbFirstName->Text = "Prenom : " + client->getFirstName();
//			LbLastName->Text = "Nom : " + client->getLastName();
//			LbBirthDay->Text = "Date de naissance : " + client->getBirthday()->ToString("dd/MM/yyyy");
//			LbTypeClient->Text = "Type de client : " + client->getTypeClient();
//		}
//
//		ClientDetails(Address^ address) : address(address)
//		{
//			// Adresse de facturation
//			LbNumeroBilling->Text = "Numero : " + address->;
//			LbStreetBilling->Text = "Rue : " + address->BillingAddress->Street;
//			LbAdditionBilling->Text = "Complement : " + address->BillingAddress->Addition;
//			LbPostalCodeBilling->Text = "Code postal : " + address->BillingAddress->PostalCode;
//			LbCityBilling->Text = "Ville : " + address->BillingAddress->City;
//
//			// Adresse de livraison
//			LbNumeroDelivery->Text = "Numéro : " + address->DeliveryAddress->Numero;
//			LbStreetDelivery->Text = "Rue : " + address->DeliveryAddress->Street;
//			LbAdditionDelivery->Text = "Complement : " + address->DeliveryAddress->Addition;
//			LbPostalCodeDelivery->Text = "Code postal : " + address->DeliveryAddress->PostalCode;
//			LbCityDelivery->Text = "Ville : " + address->DeliveryAddress->City;
//		}
//
//	protected:
//		/// <summary>
//		/// Nettoyage des ressources utilisées.
//		/// </summary>
//		~ClientDetails()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//
//	protected:
//
//
//	private:
//		/// <summary>
//		/// Variable nécessaire au concepteur.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
//		/// le contenu de cette méthode avec l'éditeur de code.
//		/// </summary>
//		void InitializeComponent(void)
//		{	
//			this->LbProfilDetails = (gcnew System::Windows::Forms::Label());
//			this->LbFirstName = (gcnew System::Windows::Forms::Label());
//			this->LbBirthDay = (gcnew System::Windows::Forms::Label());
//			this->LbLastName = (gcnew System::Windows::Forms::Label());
//			this->LbTypeClient = (gcnew System::Windows::Forms::Label());
//			this->LbInfosClient = (gcnew System::Windows::Forms::Label());
//			this->LbBillingAddress = (gcnew System::Windows::Forms::Label());
//			this->LbNumeroBilling = (gcnew System::Windows::Forms::Label());
//			this->LbStreetBilling = (gcnew System::Windows::Forms::Label());
//			this->LbPostalCodeBilling = (gcnew System::Windows::Forms::Label());
//			this->LbCityBilling = (gcnew System::Windows::Forms::Label());
//			this->LbAdditionBilling = (gcnew System::Windows::Forms::Label());
//			this->LbDeliveryAdress = (gcnew System::Windows::Forms::Label());
//			this->LbNumeroDelivery = (gcnew System::Windows::Forms::Label());
//			this->LbStreetDelivery = (gcnew System::Windows::Forms::Label());
//			this->LbAdditionDelivery = (gcnew System::Windows::Forms::Label());
//			this->LbPostalCodeDelivery = (gcnew System::Windows::Forms::Label());
//			this->LbCityDelivery = (gcnew System::Windows::Forms::Label());
//			this->SuspendLayout();
//			// 
//			// LbProfilDetails
//			// 
//			this->LbProfilDetails->AutoSize = true;
//			this->LbProfilDetails->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbProfilDetails->Location = System::Drawing::Point(379, 9);
//			this->LbProfilDetails->Name = L"LbProfilDetails";
//			this->LbProfilDetails->Size = System::Drawing::Size(260, 28);
//			this->LbProfilDetails->TabIndex = 0;
//			this->LbProfilDetails->Text = L"Details de votre profil";
//			// 
//			// LbFirstName
//			// 
//			this->LbFirstName->AutoSize = true;
//			this->LbFirstName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbFirstName->Location = System::Drawing::Point(21, 199);
//			this->LbFirstName->Name = L"LbFirstName";
//			this->LbFirstName->Size = System::Drawing::Size(65, 19);
//			this->LbFirstName->TabIndex = 1;
//			this->LbFirstName->Text = L"Prenom";
//			// 
//			// LbBirthDay
//			// 
//			this->LbBirthDay->AutoSize = true;
//			this->LbBirthDay->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbBirthDay->Location = System::Drawing::Point(21, 235);
//			this->LbBirthDay->Name = L"LbBirthDay";
//			this->LbBirthDay->Size = System::Drawing::Size(143, 19);
//			this->LbBirthDay->TabIndex = 2;
//			this->LbBirthDay->Text = L"Date de naissance";
//			// 
//			// LbLastName
//			// 
//			this->LbLastName->AutoSize = true;
//			this->LbLastName->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbLastName->Location = System::Drawing::Point(21, 162);
//			this->LbLastName->Name = L"LbLastName";
//			this->LbLastName->Size = System::Drawing::Size(44, 19);
//			this->LbLastName->TabIndex = 2;
//			this->LbLastName->Text = L"Nom";
//			// 
//			// LbTypeClient
//			// 
//			this->LbTypeClient->AutoSize = true;
//			this->LbTypeClient->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbTypeClient->Location = System::Drawing::Point(21, 278);
//			this->LbTypeClient->Name = L"LbTypeClient";
//			this->LbTypeClient->Size = System::Drawing::Size(112, 19);
//			this->LbTypeClient->TabIndex = 3;
//			this->LbTypeClient->Text = L"Type de client";
//			// 
//			// LbInfosClient
//			// 
//			this->LbInfosClient->AutoSize = true;
//			this->LbInfosClient->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbInfosClient->Location = System::Drawing::Point(21, 105);
//			this->LbInfosClient->Name = L"LbInfosClient";
//			this->LbInfosClient->Size = System::Drawing::Size(172, 22);
//			this->LbInfosClient->TabIndex = 4;
//			this->LbInfosClient->Text = L"Vos Informations :";
//			// 
//			// LbBillingAddress
//			// 
//			this->LbBillingAddress->AutoSize = true;
//			this->LbBillingAddress->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbBillingAddress->Location = System::Drawing::Point(402, 105);
//			this->LbBillingAddress->Name = L"LbBillingAddress";
//			this->LbBillingAddress->Size = System::Drawing::Size(211, 22);
//			this->LbBillingAddress->TabIndex = 5;
//			this->LbBillingAddress->Text = L"Adresse de facturation";
//			// 
//			// LbNumeroBilling
//			// 
//			this->LbNumeroBilling->AutoSize = true;
//			this->LbNumeroBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbNumeroBilling->Location = System::Drawing::Point(402, 162);
//			this->LbNumeroBilling->Name = L"LbNumeroBilling";
//			this->LbNumeroBilling->Size = System::Drawing::Size(69, 19);
//			this->LbNumeroBilling->TabIndex = 6;
//			this->LbNumeroBilling->Text = L"Numero";
//			// 
//			// LbStreetBilling
//			// 
//			this->LbStreetBilling->AutoSize = true;
//			this->LbStreetBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbStreetBilling->Location = System::Drawing::Point(402, 199);
//			this->LbStreetBilling->Name = L"LbStreetBilling";
//			this->LbStreetBilling->Size = System::Drawing::Size(37, 19);
//			this->LbStreetBilling->TabIndex = 7;
//			this->LbStreetBilling->Text = L"Rue";
//			// 
//			// LbPostalCodeBilling
//			// 
//			this->LbPostalCodeBilling->AutoSize = true;
//			this->LbPostalCodeBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbPostalCodeBilling->Location = System::Drawing::Point(402, 278);
//			this->LbPostalCodeBilling->Name = L"LbPostalCodeBilling";
//			this->LbPostalCodeBilling->Size = System::Drawing::Size(99, 19);
//			this->LbPostalCodeBilling->TabIndex = 8;
//			this->LbPostalCodeBilling->Text = L"Code postal";
//			// 
//			// LbCityBilling
//			// 
//			this->LbCityBilling->AutoSize = true;
//			this->LbCityBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbCityBilling->Location = System::Drawing::Point(402, 323);
//			this->LbCityBilling->Name = L"LbCityBilling";
//			this->LbCityBilling->Size = System::Drawing::Size(43, 19);
//			this->LbCityBilling->TabIndex = 9;
//			this->LbCityBilling->Text = L"Ville";
//			// 
//			// LbAdditionBilling
//			// 
//			this->LbAdditionBilling->AutoSize = true;
//			this->LbAdditionBilling->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbAdditionBilling->Location = System::Drawing::Point(402, 235);
//			this->LbAdditionBilling->Name = L"LbAdditionBilling";
//			this->LbAdditionBilling->Size = System::Drawing::Size(105, 19);
//			this->LbAdditionBilling->TabIndex = 10;
//			this->LbAdditionBilling->Text = L"Complément";
//			// 
//			// LbDeliveryAdress
//			// 
//			this->LbDeliveryAdress->AutoSize = true;
//			this->LbDeliveryAdress->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbDeliveryAdress->Location = System::Drawing::Point(805, 105);
//			this->LbDeliveryAdress->Name = L"LbDeliveryAdress";
//			this->LbDeliveryAdress->Size = System::Drawing::Size(190, 22);
//			this->LbDeliveryAdress->TabIndex = 11;
//			this->LbDeliveryAdress->Text = L"Adresse de livraison";
//			// 
//			// LbNumeroDelivery
//			// 
//			this->LbNumeroDelivery->AutoSize = true;
//			this->LbNumeroDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbNumeroDelivery->Location = System::Drawing::Point(805, 162);
//			this->LbNumeroDelivery->Name = L"LbNumeroDelivery";
//			this->LbNumeroDelivery->Size = System::Drawing::Size(69, 19);
//			this->LbNumeroDelivery->TabIndex = 12;
//			this->LbNumeroDelivery->Text = L"Numero";
//			// 
//			// LbStreetDelivery
//			// 
//			this->LbStreetDelivery->AutoSize = true;
//			this->LbStreetDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbStreetDelivery->Location = System::Drawing::Point(805, 199);
//			this->LbStreetDelivery->Name = L"LbStreetDelivery";
//			this->LbStreetDelivery->Size = System::Drawing::Size(37, 19);
//			this->LbStreetDelivery->TabIndex = 13;
//			this->LbStreetDelivery->Text = L"Rue";
//			// 
//			// LbAdditionDelivery
//			// 
//			this->LbAdditionDelivery->AutoSize = true;
//			this->LbAdditionDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbAdditionDelivery->Location = System::Drawing::Point(805, 235);
//			this->LbAdditionDelivery->Name = L"LbAdditionDelivery";
//			this->LbAdditionDelivery->Size = System::Drawing::Size(105, 19);
//			this->LbAdditionDelivery->TabIndex = 14;
//			this->LbAdditionDelivery->Text = L"Complément";
//			// 
//			// LbPostalCodeDelivery
//			// 
//			this->LbPostalCodeDelivery->AutoSize = true;
//			this->LbPostalCodeDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbPostalCodeDelivery->Location = System::Drawing::Point(805, 278);
//			this->LbPostalCodeDelivery->Name = L"LbPostalCodeDelivery";
//			this->LbPostalCodeDelivery->Size = System::Drawing::Size(99, 19);
//			this->LbPostalCodeDelivery->TabIndex = 15;
//			this->LbPostalCodeDelivery->Text = L"Code postal";
//			// 
//			// LbCityDelivery
//			// 
//			this->LbCityDelivery->AutoSize = true;
//			this->LbCityDelivery->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->LbCityDelivery->Location = System::Drawing::Point(805, 323);
//			this->LbCityDelivery->Name = L"LbCityDelivery";
//			this->LbCityDelivery->Size = System::Drawing::Size(43, 19);
//			this->LbCityDelivery->TabIndex = 16;
//			this->LbCityDelivery->Text = L"Ville";
//			// 
//			// ClientDetails
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(1024, 445);
//			this->Controls->Add(this->LbCityDelivery);
//			this->Controls->Add(this->LbPostalCodeDelivery);
//			this->Controls->Add(this->LbAdditionDelivery);
//			this->Controls->Add(this->LbStreetDelivery);
//			this->Controls->Add(this->LbNumeroDelivery);
//			this->Controls->Add(this->LbDeliveryAdress);
//			this->Controls->Add(this->LbAdditionBilling);
//			this->Controls->Add(this->LbCityBilling);
//			this->Controls->Add(this->LbPostalCodeBilling);
//			this->Controls->Add(this->LbStreetBilling);
//			this->Controls->Add(this->LbNumeroBilling);
//			this->Controls->Add(this->LbBillingAddress);
//			this->Controls->Add(this->LbInfosClient);
//			this->Controls->Add(this->LbTypeClient);
//			this->Controls->Add(this->LbLastName);
//			this->Controls->Add(this->LbBirthDay);
//			this->Controls->Add(this->LbFirstName);
//			this->Controls->Add(this->LbProfilDetails);
//			this->Name = L"ClientDetails";
//			this->Text = L"ClientDetails";
//			this->ResumeLayout(false);
//			this->PerformLayout();
//
//		}
//#pragma endregion
//	};
//}
