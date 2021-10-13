#ifndef PESSOA_HPP
#define PESSOA_HPP

#include<string>

class Pessoa{
	public:
		Pessoa();
		Pessoa(std::string nome);
		Pessoa(std::string nome, unsigned short int idade);
		Pessoa(std::string nome, long long cpfPessoa, unsigned short int idade);

		unsigned long getCpf();
		bool setCpf(unsigned long cpf);

		std::string getNome();
		void setNome(std::string nome);

		unsigned short int getIdade();
		void setIdade(unsigned short int idade);
		
	private:
		bool validarCPF(unsigned long cpf);

		std::string nome;
		unsigned long cpf;
		unsigned char idade;
};
#endif
