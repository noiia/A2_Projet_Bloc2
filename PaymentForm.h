#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include "BDD.h"
#include "CartRepository.h"
#include "Command.h"
namespace A2ProjetBloc2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Description r�sum�e de Cart
	/// </summary>
	public ref class PaymentForm : public System::Windows::Forms::Form
	{
		BDD^ mabdd;
		CartRepository^ cartRepository;
		Thread^ reloadThread;
		Command^ command;
		float totalAmount;
	private: System::Windows::Forms::NumericUpDown^ NudFirstMonth;
	private: System::Windows::Forms::NumericUpDown^ NudSecondMonth;
	private: System::Windows::Forms::NumericUpDown^ NudThirdMonth;
		   System::Threading::Mutex^ reloadMutex;
	public:
		PaymentForm(BDD^ mabdd, Command^ command)
		{
			this->command = command;
			this->mabdd = mabdd;
			totalAmount = this->command->getCommandAmount();
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			reloadMutex = gcnew System::Threading::Mutex();

			DGVCart->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			DataGridViewTextBoxColumn^ dgvtbcReference = gcnew DataGridViewTextBoxColumn();
			dgvtbcReference->Name = "Références";
			this->DGVCart->Columns->Add(dgvtbcReference);
			DataGridViewTextBoxColumn^ dgvtbcNameArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcNameArticle->Name = "Nom de l'article";
			this->DGVCart->Columns->Add(dgvtbcNameArticle);
			DataGridViewTextBoxColumn^ dgvtbcIdArticle = gcnew DataGridViewTextBoxColumn();
			dgvtbcIdArticle->Name = "IdArticle";
			this->DGVCart->Columns->Add(dgvtbcIdArticle);
			DataGridViewTextBoxColumn^ dgvtbcQuantity = gcnew DataGridViewTextBoxColumn();
			dgvtbcQuantity->Name = "Quantité";
			this->DGVCart->Columns->Add(dgvtbcQuantity);
			DataGridViewTextBoxColumn^ dgvtbcPriceATI = gcnew DataGridViewTextBoxColumn();
			dgvtbcPriceATI->Name = "Prix TCC de l'article";
			this->DGVCart->Columns->Add(dgvtbcPriceATI);
			DataGridViewTextBoxColumn^ dgvtbcTotalPrice = gcnew DataGridViewTextBoxColumn();
			dgvtbcTotalPrice->Name = "Prix total";
			this->DGVCart->Columns->Add(dgvtbcTotalPrice);
			cartRepository = gcnew CartRepository(mabdd);

			this->reload();
		}
		void reload() {
			if (reloadMutex != nullptr) {
				reloadMutex->WaitOne();
				System::Collections::Generic::List<Command^>^ articles = cartRepository->getArticle(command->getReference());
				//this->DGVCart->Rows->Clear();
				for each (Command ^ a in articles) {
					DataGridViewRow^ dgvr = gcnew DataGridViewRow();

					DataGridViewTextBoxCell^ dgvcReference = gcnew DataGridViewTextBoxCell();
					dgvcReference->Value = a->getReference();
					dgvr->Cells->Add(dgvcReference);
					DataGridViewTextBoxCell^ dgvcPriceATI = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcName = gcnew DataGridViewTextBoxCell();
					DataGridViewTextBoxCell^ dgvcIdArticle = gcnew DataGridViewTextBoxCell();
					Decimal^ PriceATI = Decimal(0);
					String^ Name;
					String^ IdArticle;
					for each (Article ^ art in a->getArticle()) {
						PriceATI = (Decimal^)art->getPriceATI();
						Name = (String^)art->getName();
						IdArticle = (String^)art->getIdArticle();
					}
					dgvcPriceATI->Value = PriceATI;
					dgvcName->Value = Name;
					dgvr->Cells->Add(dgvcName);
					dgvcIdArticle->Value = IdArticle;
					dgvr->Cells->Add(dgvcIdArticle);
					DataGridViewTextBoxCell^ dgvcQuantity = gcnew DataGridViewTextBoxCell();
					dgvcQuantity->Value = a->getQuantity();
					dgvr->Cells->Add(dgvcQuantity);
					dgvr->Cells->Add(dgvcPriceATI);

					DataGridViewTextBoxCell^ dgvcTotal = gcnew DataGridViewTextBoxCell();
					dgvcTotal->Value = a->getQuantity() * Convert::ToSingle(PriceATI);
					dgvr->Cells->Add(dgvcTotal);

					dgvr->Tag = a;
					this->DGVCart->Rows->Add(dgvr);

				}
				reloadMutex->ReleaseMutex();
			}
		}
		void launchReloadThread() {
			reloadThread = gcnew Thread(gcnew ThreadStart(this, &PaymentForm::reload));
			reloadThread->Start();
		}
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~PaymentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Title;
	private: System::Windows::Forms::TextBox^ TboxPaymentType;
	protected:

	protected:

	private: System::Windows::Forms::Label^ LbPaymentType;
private: System::Windows::Forms::Label^ LbNumberOfPayment;
private: System::Windows::Forms::DateTimePicker^ DtpFirstPayment;




	private: System::Windows::Forms::Label^ LbFirstPayment;
	private: System::Windows::Forms::Label^ LbSecondPayment;
private: System::Windows::Forms::DateTimePicker^ DtpSecondPayment;



	private: System::Windows::Forms::Label^ LbThirdPayment;
private: System::Windows::Forms::DateTimePicker^ DtpThirdPayment;


	private: System::Windows::Forms::Label^ LbRemember;
	private: System::Windows::Forms::Label^ LbTotalPrice;
private: System::Windows::Forms::DataGridView^ DGVCart;
private: System::Windows::Forms::NumericUpDown^ NudNumberOfPayment;





	private: System::Windows::Forms::Button^ BtnModifyCommand;
	private: System::Windows::Forms::Button^ BtnPayment;



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PaymentForm::typeid));
			this->Title = (gcnew System::Windows::Forms::Label());
			this->TboxPaymentType = (gcnew System::Windows::Forms::TextBox());
			this->LbPaymentType = (gcnew System::Windows::Forms::Label());
			this->LbNumberOfPayment = (gcnew System::Windows::Forms::Label());
			this->DtpFirstPayment = (gcnew System::Windows::Forms::DateTimePicker());
			this->LbFirstPayment = (gcnew System::Windows::Forms::Label());
			this->LbSecondPayment = (gcnew System::Windows::Forms::Label());
			this->DtpSecondPayment = (gcnew System::Windows::Forms::DateTimePicker());
			this->LbThirdPayment = (gcnew System::Windows::Forms::Label());
			this->DtpThirdPayment = (gcnew System::Windows::Forms::DateTimePicker());
			this->LbRemember = (gcnew System::Windows::Forms::Label());
			this->LbTotalPrice = (gcnew System::Windows::Forms::Label());
			this->DGVCart = (gcnew System::Windows::Forms::DataGridView());
			this->NudNumberOfPayment = (gcnew System::Windows::Forms::NumericUpDown());
			this->BtnModifyCommand = (gcnew System::Windows::Forms::Button());
			this->BtnPayment = (gcnew System::Windows::Forms::Button());
			this->NudFirstMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->NudSecondMonth = (gcnew System::Windows::Forms::NumericUpDown());
			this->NudThirdMonth = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudNumberOfPayment))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudFirstMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudSecondMonth))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudThirdMonth))->BeginInit();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Orkney", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Title->Location = System::Drawing::Point(331, 20);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(116, 29);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Paiement";
			// 
			// TboxPaymentType
			// 
			this->TboxPaymentType->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TboxPaymentType->Location = System::Drawing::Point(36, 119);
			this->TboxPaymentType->Name = L"TboxPaymentType";
			this->TboxPaymentType->Size = System::Drawing::Size(207, 26);
			this->TboxPaymentType->TabIndex = 1;
			// 
			// LbPaymentType
			// 
			this->LbPaymentType->AutoSize = true;
			this->LbPaymentType->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbPaymentType->Location = System::Drawing::Point(33, 92);
			this->LbPaymentType->Name = L"LbPaymentType";
			this->LbPaymentType->Size = System::Drawing::Size(142, 19);
			this->LbPaymentType->TabIndex = 2;
			this->LbPaymentType->Text = L"Type de paiement";
			// 
			// LbNumberOfPayment
			// 
			this->LbNumberOfPayment->AutoSize = true;
			this->LbNumberOfPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbNumberOfPayment->Location = System::Drawing::Point(33, 176);
			this->LbNumberOfPayment->Name = L"LbNumberOfPayment";
			this->LbNumberOfPayment->Size = System::Drawing::Size(187, 19);
			this->LbNumberOfPayment->TabIndex = 4;
			this->LbNumberOfPayment->Text = L"Nombre de mensualités";
			// 
			// DtpFirstPayment
			// 
			this->DtpFirstPayment->Location = System::Drawing::Point(37, 402);
			this->DtpFirstPayment->Name = L"DtpFirstPayment";
			this->DtpFirstPayment->Size = System::Drawing::Size(200, 20);
			this->DtpFirstPayment->TabIndex = 3;
			// 
			// LbFirstPayment
			// 
			this->LbFirstPayment->AutoSize = true;
			this->LbFirstPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbFirstPayment->Location = System::Drawing::Point(34, 372);
			this->LbFirstPayment->Name = L"LbFirstPayment";
			this->LbFirstPayment->Size = System::Drawing::Size(162, 19);
			this->LbFirstPayment->TabIndex = 6;
			this->LbFirstPayment->Text = L"Première mensualité";
			// 
			// LbSecondPayment
			// 
			this->LbSecondPayment->AutoSize = true;
			this->LbSecondPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbSecondPayment->Location = System::Drawing::Point(298, 372);
			this->LbSecondPayment->Name = L"LbSecondPayment";
			this->LbSecondPayment->Size = System::Drawing::Size(170, 19);
			this->LbSecondPayment->TabIndex = 8;
			this->LbSecondPayment->Text = L"Deuxième mensualité";
			// 
			// DtpSecondPayment
			// 
			this->DtpSecondPayment->Enabled = false;
			this->DtpSecondPayment->Location = System::Drawing::Point(301, 402);
			this->DtpSecondPayment->Name = L"DtpSecondPayment";
			this->DtpSecondPayment->Size = System::Drawing::Size(200, 20);
			this->DtpSecondPayment->TabIndex = 4;
			// 
			// LbThirdPayment
			// 
			this->LbThirdPayment->AutoSize = true;
			this->LbThirdPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbThirdPayment->Location = System::Drawing::Point(566, 372);
			this->LbThirdPayment->Name = L"LbThirdPayment";
			this->LbThirdPayment->Size = System::Drawing::Size(166, 19);
			this->LbThirdPayment->TabIndex = 10;
			this->LbThirdPayment->Text = L"Troisième mensualité";
			// 
			// DtpThirdPayment
			// 
			this->DtpThirdPayment->Enabled = false;
			this->DtpThirdPayment->Location = System::Drawing::Point(569, 402);
			this->DtpThirdPayment->Name = L"DtpThirdPayment";
			this->DtpThirdPayment->Size = System::Drawing::Size(200, 20);
			this->DtpThirdPayment->TabIndex = 5;
			// 
			// LbRemember
			// 
			this->LbRemember->AutoSize = true;
			this->LbRemember->Font = (gcnew System::Drawing::Font(L"Orkney", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbRemember->Location = System::Drawing::Point(350, 66);
			this->LbRemember->Name = L"LbRemember";
			this->LbRemember->Size = System::Drawing::Size(231, 23);
			this->LbRemember->TabIndex = 11;
			this->LbRemember->Text = L"Contenu de la commande";
			// 
			// LbTotalPrice
			// 
			this->LbTotalPrice->AutoSize = true;
			this->LbTotalPrice->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LbTotalPrice->Location = System::Drawing::Point(33, 276);
			this->LbTotalPrice->Name = L"LbTotalPrice";
			this->LbTotalPrice->Size = System::Drawing::Size(102, 19);
			this->LbTotalPrice->TabIndex = 12;
			this->LbTotalPrice->Text = L"Sous-total : ";
			// 
			// DGVCart
			// 
			this->DGVCart->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DGVCart->Location = System::Drawing::Point(294, 92);
			this->DGVCart->Name = L"DGVCart";
			this->DGVCart->Size = System::Drawing::Size(467, 243);
			this->DGVCart->TabIndex = 13;
			// 
			// NudNumberOfPayment
			// 
			this->NudNumberOfPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudNumberOfPayment->Location = System::Drawing::Point(36, 219);
			this->NudNumberOfPayment->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->NudNumberOfPayment->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NudNumberOfPayment->Name = L"NudNumberOfPayment";
			this->NudNumberOfPayment->Size = System::Drawing::Size(207, 26);
			this->NudNumberOfPayment->TabIndex = 2;
			this->NudNumberOfPayment->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->NudNumberOfPayment->ValueChanged += gcnew System::EventHandler(this, &PaymentForm::NudNumberOfPayment_ValueChanged);
			// 
			// BtnModifyCommand
			// 
			this->BtnModifyCommand->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnModifyCommand->Location = System::Drawing::Point(82, 501);
			this->BtnModifyCommand->Name = L"BtnModifyCommand";
			this->BtnModifyCommand->Size = System::Drawing::Size(117, 41);
			this->BtnModifyCommand->TabIndex = 6;
			this->BtnModifyCommand->Text = L"Modifier";
			this->BtnModifyCommand->UseVisualStyleBackColor = true;
			this->BtnModifyCommand->Click += gcnew System::EventHandler(this, &PaymentForm::BtnModifyCommand_Click);
			// 
			// BtnPayment
			// 
			this->BtnPayment->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnPayment->Location = System::Drawing::Point(604, 501);
			this->BtnPayment->Name = L"BtnPayment";
			this->BtnPayment->Size = System::Drawing::Size(117, 41);
			this->BtnPayment->TabIndex = 7;
			this->BtnPayment->Text = L"Payer";
			this->BtnPayment->UseVisualStyleBackColor = true;
			this->BtnPayment->Click += gcnew System::EventHandler(this, &PaymentForm::BtnPayment_Click);
			// 
			// NudFirstMonth
			// 
			this->NudFirstMonth->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudFirstMonth->Location = System::Drawing::Point(38, 448);
			this->NudFirstMonth->Name = L"NudFirstMonth";
			this->NudFirstMonth->Size = System::Drawing::Size(199, 26);
			this->NudFirstMonth->TabIndex = 15;
			// 
			// NudSecondMonth
			// 
			this->NudSecondMonth->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudSecondMonth->Location = System::Drawing::Point(302, 448);
			this->NudSecondMonth->Name = L"NudSecondMonth";
			this->NudSecondMonth->Size = System::Drawing::Size(199, 26);
			this->NudSecondMonth->TabIndex = 16;
			// 
			// NudThirdMonth
			// 
			this->NudThirdMonth->Font = (gcnew System::Drawing::Font(L"Orkney", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NudThirdMonth->Location = System::Drawing::Point(569, 448);
			this->NudThirdMonth->Name = L"NudThirdMonth";
			this->NudThirdMonth->Size = System::Drawing::Size(200, 26);
			this->NudThirdMonth->TabIndex = 17;
			this->NudFirstMonth->Maximum = Convert::ToDecimal(999999999);
			this->NudSecondMonth->Maximum = Convert::ToDecimal(999999999);
			this->NudThirdMonth->Maximum = Convert::ToDecimal(999999999);
			// 
			// PaymentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(795, 569);
			this->Controls->Add(this->NudThirdMonth);
			this->Controls->Add(this->NudSecondMonth);
			this->Controls->Add(this->NudFirstMonth);
			this->Controls->Add(this->BtnPayment);
			this->Controls->Add(this->BtnModifyCommand);
			this->Controls->Add(this->NudNumberOfPayment);
			this->Controls->Add(this->DGVCart);
			this->Controls->Add(this->LbTotalPrice);
			this->Controls->Add(this->LbRemember);
			this->Controls->Add(this->LbThirdPayment);
			this->Controls->Add(this->DtpThirdPayment);
			this->Controls->Add(this->LbSecondPayment);
			this->Controls->Add(this->DtpSecondPayment);
			this->Controls->Add(this->LbFirstPayment);
			this->Controls->Add(this->DtpFirstPayment);
			this->Controls->Add(this->LbNumberOfPayment);
			this->Controls->Add(this->LbPaymentType);
			this->Controls->Add(this->TboxPaymentType);
			this->Controls->Add(this->Title);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PaymentForm";
			this->Text = L"PaymentForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DGVCart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudNumberOfPayment))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudFirstMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudSecondMonth))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->NudThirdMonth))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BtnModifyCommand_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void BtnPayment_Click(System::Object^ sender, System::EventArgs^ e) {
	this->command->setPaymentMode(this->TboxPaymentType->Text);
	this->command->setNumberOfPayment(Convert::ToSingle(this->NudNumberOfPayment->Value));

	switch (Convert::ToInt32(this->NudNumberOfPayment->Value)) {
	case 3:{
		String ^ thirdDateString = this->DtpThirdPayment->Value.ToString("yyyy-MM-dd");
		DateTime thirdDate = DateTime::ParseExact(thirdDateString, "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
		this->command->setThirdPayment(thirdDate);
		this->command->setThirdAmount(Convert::ToSingle(this->NudThirdMonth->Value));
		//fall through
	}case 2: {
		String ^ secondDateString = this->DtpSecondPayment->Value.ToString("yyyy-MM-dd");
		DateTime secondDate = DateTime::ParseExact(secondDateString, "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
		this->command->setSecondPayment(secondDate);
		this->command->setSecondAmount(Convert::ToSingle(this->NudSecondMonth->Value));
		//fall through
	}case 1: {
		String^ firstDateString = this->DtpFirstPayment->Value.ToString("yyyy-MM-dd");
		DateTime firstDate = DateTime::ParseExact(firstDateString, "yyyy-MM-dd", System::Globalization::CultureInfo::InvariantCulture);
		this->command->setFirstPayment(firstDate);
		this->command->setFirstAmount(Convert::ToSingle(this->NudFirstMonth->Value));
		//fall through
	}
	default:
		break;
	};
	this->Close();
}
private: System::Void NudNumberOfPayment_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	switch (Convert::ToInt32(this->NudNumberOfPayment->Value)) {
	case 3: {
		this->DtpSecondPayment->Enabled = true;
		this->DtpThirdPayment->Enabled = true;
		this->NudSecondMonth->Enabled = true;
		this->NudThirdMonth->Enabled = true;
		this->NudFirstMonth->Value = Convert::ToDecimal(totalAmount / 3);
		this->NudSecondMonth->Value = Convert::ToDecimal(totalAmount / 3);
		this->NudThirdMonth->Value = Convert::ToDecimal(totalAmount / 3);
		break;
	}case 2: {
		this->DtpSecondPayment->Enabled = true;
		this->NudSecondMonth->Enabled = true;
		this->NudThirdMonth->Enabled = false;
		this->DtpThirdPayment->Enabled = false;
		this->NudFirstMonth->Value = Convert::ToDecimal(totalAmount / 2);
		this->NudSecondMonth->Value = Convert::ToDecimal(totalAmount / 2);
		this->NudThirdMonth->Value = 0;

		break;
	}case 1: {
		this->NudSecondMonth->Enabled = false;
		this->DtpThirdPayment->Enabled = false;
		this->DtpSecondPayment->Enabled = false;
		this->DtpThirdPayment->Enabled = false;
		this->NudFirstMonth->Value = Convert::ToDecimal(totalAmount);
		this->NudSecondMonth->Value = 0;
		this->NudThirdMonth->Value = 0;

		break;
	}default:
		break;
	};
}
};
}
