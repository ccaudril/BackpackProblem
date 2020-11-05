#include "Backpack.h"
#include<iostream>

Backpack::Backpack()
{
}

Backpack::Backpack(vector<int> valors, vector<int> pesos, int capacitat_total, int n_elements)
{
	m_num_elements = n_elements;

	m_valors.resize(m_num_elements);
	m_pesos.resize(m_num_elements);

	for (int i = 0; i < m_num_elements; i++) {
		m_valors[i] = valors[i];
		m_pesos[i] = pesos[i];
	}
	m_capacitat_total = capacitat_total;

}

Backpack::~Backpack()
{
}

void Backpack::AvaluaBackpack_back(int nivell, int pes_act, int valor_act, vector<int>& sol_act, vector<int>& sol_opt, int& ben_opt, int& pes_opt) {
	int i;
	for (i = 1; i >= 0; i--) {
		sol_act[nivell] = i;
		pes_act += i * m_pesos[nivell];
		valor_act += i * m_valors[nivell];
		if (nivell == m_num_elements - 1) {
			if (pes_act <= m_capacitat_total && valor_act >= ben_opt) {
				pes_opt = pes_act;
				ben_opt = valor_act;
				sol_opt = sol_act;
			}
		}
		else if(pes_act <= m_capacitat_total){
			AvaluaBackpack_back(nivell + 1, pes_act, valor_act, sol_act, sol_opt, ben_opt, pes_opt);
		}
		sol_act[nivell] = 0;
		pes_act -= i * m_pesos[nivell];
		valor_act -= i * m_valors[nivell];
	}
}