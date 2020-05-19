#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::dec;
using std::fixed;
#include <algorithm>
using std::for_each;
using std::swap;

enum Param{ N = 0, K, MAX };
enum Mode{ MODE_INVALID = 0, ARRANGEMENT, PERMUTATION, COMBINAISON, EXIT, NB_MODE };
enum Repetition{ TYPE_INVALID = 0, AVEC, SANS, NB_TYPE };

static int cpt = 0;

// Foncteur
struct Afficher {
	template<class T> void operator()( const T val ) {
		cout << val << endl;
	}
};

// tools
template<class T> void switchValue( T & v1, T & v2) {
	swap(v1, v2);
}

int GetType() {
	int type = TYPE_INVALID;

	while ( !type )
	{
		system("cls");
		cout << "Entrez la version de l'Algo : " << endl;
		cout << "1. avec repetition " << endl;
		cout << "2. sans repetition " << endl;
		cout << ">";
		cin >> type;
		type = type > 0 && type < NB_TYPE? type: TYPE_INVALID;
	}

	return type;
}

template <> void switchValue<int>( int & v1, int & v2) {
	v1 = v1^v2;
	v2 = v2^v1;
	v1 = v1^v2;
}

// Algo
int Arrangement( int n, int k, int rep ) {

	if( k < 0 || k > n ) {
		return 0;
	}

	int ank = 1;
	switch (rep)
	{
	case AVEC:
		// avec répétition
		//	k
		// A  =  n^k
		//	n

		for( int i = 0; i < k; ++i ) {
			ank *= n;
		}
		break;

	case SANS:
		// sans répétition
		//	k
		// A  =  n! / (n-k)! = (n^k) - n
		//	n

		for( int i = n-k+1; i <= n; ++i ) {
			ank *= i;
		}
		break;
	}

	return ank;
}

int Permutation( int n, int k, int rep ) {

	int pn = 1;
	switch (rep)
	{
	case AVEC:
		// avec répétition
		//	
		// P  = n!/k!
		//	n

		for( int i = k; i <= n; ++i ) {
			pn *= i;
		}
		break;

	case SANS:
		// sans répétition
		//		 n
		// P  = A  = n!
		//	n	 n

		pn = Arrangement(n, n, SANS);
		break;
	}

	return pn;
}

int Combinaison( int n, int k, int rep ) {

	int pn = 1;
	switch (rep)
	{
	case AVEC:
		// avec remise
		//	k
		// C  =	 (n+k-1)! / k!(n-1)!  => triangle de pascal  
		//	n+k-1

		break;

	case SANS:
		// sans remise
		//	k	 k
		// C  = A  / P  = n! / k!(n-k)! = coeff binomial = ( n k ); 
		//	n	 n	  k

		pn = Arrangement(n, k, rep) / Arrangement(k, k, rep);
		break;
	}

	return pn;

	return 0;
}

// entry point
int main() {
	bool loop = true;
	int mode = MODE_INVALID;

	while( loop ) {
		system("cls");
		cout << "faite votre choix: " << endl;
		cout << "1. Arrangement " << endl;
		cout << "2. Permutation " << endl;
		cout << "3. Combinaison " << endl;
		cout << "4. Quitter " << endl;
		cout << ">";
		cin >> mode;

		int id = N;
		int vals[MAX];
		int repetition;

		switch (mode)
		{
		case ARRANGEMENT:
		{
			system("cls");
			repetition = GetType();
			const char * rep = repetition==AVEC?"avec":"sans";

			while ( id == N ) {
				system("cls");
				cout << "entrez le nombre d'elements : ";
				cin >> vals[id];
				if ( vals[id] > 0) {
					++id;
				}
			}

			while ( id == K ) {
				system("cls");
				cout << "entrez le nombre d'objet a prendre : ";
				cin >> vals[id];
				if ( vals[id] > 0) {
					++id;
				}
			}
		
			cout << "Nombre d'arrangement possible " << rep << " repetition : ";
			cout << Arrangement(vals[N], vals[K], repetition) << endl;

			system("PAUSE");
		} break;

		case PERMUTATION: 
		{
			system("cls");
			repetition = GetType();
			const char * rep = repetition==AVEC?"avec":"sans";

			while ( id == N ) {
				system("cls");
				cout << "entrez le nombre d'elements : ";
				cin >> vals[id];
				if ( vals[id] > 0) {
					++id;
				}
			}
			
			if (repetition == AVEC) {
				while ( id == K ) {
					system("cls");
					cout << "entrez le nombre d'objet identique : ";
					cin >> vals[id];
					if ( vals[id] > 0) {
						++id;
					}
				}
			}

			cout << "Nombre de permutation possible " << rep << " repetition : ";
			cout << Permutation(vals[N], vals[K], repetition) << endl;

			system("PAUSE");
		} break;

		case COMBINAISON:
		{
			system("cls");
			repetition = GetType();
			const char * rep = repetition==AVEC?"avec":"sans";

			while ( id == N ) {
				system("cls");
				cout << "entrez le nombre d'elements : ";
				cin >> vals[id];
				if ( vals[id] > 0) {
					++id;
				}
			}

			while ( id == K ) {
				system("cls");
				cout << "entrez le nombre d'objet a prendre : ";
				cin >> vals[id];
				if ( vals[id] > 0) {
					++id;
				}
			}
			
			cout << "Nombre de permutation possible " << rep << " repetition : ";
			cout << Combinaison(vals[N], vals[K], repetition) << endl;
			system("PAUSE");
		} break;

		case EXIT:
			loop = false;
			break;

		default:
			mode = MODE_INVALID;
			break;
		}
	}

	return 0;
}