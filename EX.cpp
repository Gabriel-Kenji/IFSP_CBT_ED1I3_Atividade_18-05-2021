#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

	
class Data
{
	private:
		int dia;
		int mes;
		int ano;
		
		
	public:
		Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		
		

		
		void setDia(int dia)
		{
			this->dia = dia;
		}
		
		void setMes(int mes)
		{
			this->mes = mes;
		}

		void setAno(int ano)
		{
			this->ano = ano;
		}
		
		int getDia()
		{
			return this->dia;
		}
		
		int getMes()
		{
			return this->mes;
		}

		int getAno()
		{
			return this->ano;
		}
		
		string getData()
        {
 	        //return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
        }
        
};
class Contato{
	
	struct tm *data_hora_atual;
	
	Data dtnasc;
	string email;
	string name;
	string telefone;
	int diaN;
	int mesN;
	int anoN;
	
	public:
		Contato(Data &datas)
		{
			dtnasc = datas;
		}
 		
 		Contato( string name,string email, string telefone)
		{
			this->email = email;
			this->name = name;
			this->telefone = telefone;
		}
		
		Contato()
		{
			this->email = "";
			this->name = "";
			this->telefone = "";
		}
		
		void setEmail(string email)
		{
			this->email = email;
		}
		
		void setName(string name)
		{
			this->name = name;
		}

		void setTelefone(string telefone)
		{
			this->telefone = telefone;
		}
		
		void setDiaN(int diaN)
		{
			this->diaN = dtnasc.getDia();
		}
		
		string getEmail()
		{
			return this->email;
		}
		
		string getName()
		{
			return this->name;
		}
		
		string getTelefone()
		{
			return this->telefone;
		}
		
		Data getDtnasc()
		{
			return this->dtnasc;
		}
		
		int getDiaN()
		{
			return this->diaN;
		}
		
		void getIdade()
        {
        	
        	int ano = dtnasc.getAno();
        	int mes = dtnasc.getMes();
        	int dia = dtnasc.getDia();
        	time_t mytime;
		    mytime = time(NULL);
		    struct tm tm = *localtime(&mytime);
		    int anoA = tm.tm_year + 1900;
		    int mesA = tm.tm_mon + 1;
        	int diaA = tm.tm_mday;
			if(ano <= anoA)
			{
				if(ano == anoA)
				{
					if(mes > mesA)
					{
						cout << "invalido";
					}
					else
					{
						if(mes == mesA  )
						{
							if(dia > diaA)
							{
								cout << "invalido";
							}
							else
							{
								if(dia <= diaA)
								{
									cout <<"IDADE: " << anoA-ano;
								}
								else
								{
									cout <<"IDADE: " << anoA-ano-1;
								}
							}
								
						}
						else
						{
							if(mes < mesA)
							{
								cout <<"IDADE: " << anoA-ano;
							}
							else
							{
								if(mes == mesA)
								{
									if(dia <= diaA)
									{
										cout <<"IDADE: " << anoA-ano;
									}
									else
									{
										cout <<"IDADE: " << anoA-ano-1;
									}
								}	
								else
								{
									cout <<"IDADE: " << anoA-ano-1;
								}	
							}
								
						}
					}
					
				}
				else
				{
					
					if(mes < mesA)
					{
						cout <<"IDADE: " << anoA-ano;
					}
					else
					{
						if(mes == mesA)
						{
							if(dia <= diaA)
							{
								cout <<"IDADE: " << anoA-ano;
							}
							else
							{
								cout <<"IDADE: " << anoA-ano-1 ;
							}
						}	
						else
						{
							cout <<"IDADE: " << anoA-ano-1;
						}	
					}
				}
			}
			else
			{
				cout << "invalido";
			}
        }
        
        void getContato()
        {
        	
    		
    			
    			cout <<"NOME: "<< this->name  <<  endl <<"EMAIL: "<<this->email  <<  endl <<"TELEFONE: "<< this->telefone <<  endl; 
    			 
			
        }
};

int main(int argc, char** argv)
{
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	int anoA = tm.tm_year + 1900;
	int mesA = tm.tm_mon + 1;
    int diaA = tm.tm_mday;
	int data[5][3];
	string dados[5][3];
	
	for(int i = 0; i <5; i++)
	{
			cout <<"Contato "<<i+1<<endl<<endl;
			cout << "Digite o Nome: ";
			cin >> dados[i][0];
			cout << "Digite o Email: ";
			cin >> dados[i][1];
			cout << "Digite o Telefone: ";
			cin >> dados[i][2];
			for(int j=0; j <1; j++)
			{
				int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
				cout << "Digite o ano de nascimento: ";
				cin >> data[i][0];
				if(data[i][0]<= anoA)
				{
					if(data[i][0] == anoA)
					{
						cout << "Digite o mes de nascimento: ";
						cin >> data[i][1];
						if(data[i][1] < 13)
						{
							if(data[i][1] <= mesA )
							{
								if(data[i][1] == mesA)
								{
									if (data[i][0] % 4 == 0)
									{
										diasNoMes[1]++;
									}
									cout << "Digite o dia de nascimento: "<< diasNoMes[data[i][1]-1];
									cin >> data[i][2];
									if(data[i][2] > diaA || data[i][2] >diasNoMes[data[i][1]])
									{
										cout << "Data de Nascimento invalida!!! Digite novamente\n";
										j = j-1;
									}
									
								}
								else
								{
									if (data[i][0] % 4 == 0)
									{
										diasNoMes[1]++;
									}
										cout << "Digite o dia de nascimento: ";
										cin >> data[i][2];
									if(data[i][2] > diasNoMes[data[i][1]-1])
									{
										cout << "Data de Nascimento invalida!!! Digite novamente\n";
										j = j-1;
									}
								}
							}
							else
							{
								cout << "Data de Nascimento invalida!!! Digite novamente\n";
								j = j-1;
							}
						}
						else
						{
							cout << "Data de Nascimento invalida!!! Digite novamente\n";
							j = j-1;
						}
						
					}
					else
					{
						cout << "Digite o mes de nascimento: ";
						cin >> data[i][1];
						
						if(data[i][1] < 13)
						{
							if (data[i][0] % 4 == 0)
							{
								diasNoMes[1]++;
							}
								cout << "Digite o dia de nascimento: ";
								cin >> data[i][2];
							if(data[i][2] > diasNoMes[data[i][1]-1])
							{
								cout << "Data de Nascimento invalida!!! Digite novamente\n";
								j = j-1;
							}
						}
						else
						{
							cout << "Data de Nascimento invalida!!! Digite novamente\n";
							j = j-1;
						}
					}
				}
				else
				{
					cout << "Data de Nascimento invalida!!! Digite novamente\n";
					j = j-1;
				}
				
			}
			cout<<endl;
	}
	for(int o = 0; o < 5; o++)
	{
		cout<< endl << endl<<"CONTATO "<< o+1<<endl;
		Data datas(data[o][2],data[o][1],data[o][0]);
	    Contato contato(datas); 
		Contato *contatos = new Contato(dados[o][0],dados[o][1],dados[o][2]);
		contato.getIdade();
		cout<< endl;
		contatos->getContato();
	}
    
	
	
	
	
}
