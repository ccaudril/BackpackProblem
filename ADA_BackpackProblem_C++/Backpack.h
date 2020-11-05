#pragma once
#include<vector>

using namespace std;

class Backpack{
public:
	Backpack();
	Backpack(vector<int> valors, vector<int> pesos, int capacitat_total, int n_elements);
	~Backpack();
	void AvaluaBackpack_back(int nivell, int pes_act, int valor_act, vector<int>& sol_act, vector<int>& sol_opt, int& ben_opt, int& pes_opt);
	// void knapsack_back(vector<int>& sol_act, vector<int>& sol_opt, int ben_act, int pes_act, int k, int& ben_opt);

private:
	vector<int> m_valors;	// is the profit vector of the objects
	vector<int> m_pesos;	// is the vector of weights of the objects
	int m_capacitat_total;	// is the total capacity of the backpack
	int m_num_elements;		// is the number of objects we have

	// retorna el maxim entre dos enters
	int max(int a, int b) { return (a > b) ? a : b; }
};
