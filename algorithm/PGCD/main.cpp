#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::dec;
using std::fixed;
#include <algorithm>
using std::for_each;
using std::swap;

enum{ MAX = 2 };
enum Mode{ MODE_INVALID = 0, PGCD, AVERAGE, SWITCH, EXIT, NB_MODE };
enum Type{ TYPE_INVALID = 0, V1, V2, V3, NB_TYPE };

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

template <> void switchValue<int>( int & v1, int & v2) {
	v1 = v1^v2;
	v2 = v2^v1;
	v1 = v1^v2;
}

int GetType() {
	int type = TYPE_INVALID;

	while ( !type )
	{
		system("cls");
		cout << "Entrez la version de l'Algo : " << endl;
		cout << "1. V1 " << endl;
		cout << "2. V2 " << endl;
		cout << "3. V3 " << endl;
		cout << ">";
		cin >> type;
		type = type > 0 && type < NB_TYPE? type: TYPE_INVALID;
	}

	return type;
}

// Algo
int PGCD_V1( int num, int den ) {
	cpt = 0;
	// num = qot*den + rem
	int rem = 1;

	// if rem == 0 and num > den => den == PGCD
	while (rem) {
		++cpt;
		rem = num % den;

		// if den > num, rem == num -> infinite loop
		// => switch values for having num > den
		if (num < den) {
			switchValue(num, den);
		} else { // num <- den <- rem
			num = den;
			den = rem;
		}
	}

	return den;
}

int PGCD_V2( int num, int den ) {
	cpt = 0;
	int rem = 1;

	while (rem) {
		++cpt;

		// eval remaind
		rem = num % den;
		// if rem <> 0, num <- den <- rem
		if (rem) {
			num = den;
			den = rem;
		} 
	}

	return den;
}

int PGCD_V3( int num, int den ) {
	cpt = 0;
	int rem = num % den;

	// optimisation:
	// if num > den => rem < den always
	// no need to switch, just process on value

	while (rem) {
		++cpt;

		// if rem == 0, return den
		if (rem) {
			num = den%rem;
		} else {
			return den;
		}

		// if num == 0, return rem
		if (num) {
			den = rem%num;
		} else {
			return rem;
		}

		// if den == 0, return num
		if (den) {
			rem = num % den;
		} else {
			return num;
		}
	}

	return den;
}


void proc_PGCD( int num, int den, int type ) {
	cout << "num: " << num << " den: " << den;
	int pgcd = 0;
	
	switch(type) {
	case V1:
		pgcd = PGCD_V1(num, den);
		break;

	case V2:
		pgcd = PGCD_V2(num, den);
		break;

	case V3:
		pgcd = PGCD_V3(num, den);
		break;
	}

	cout << " PGCD: " << pgcd << " nb_cycle: " << cpt << endl;
}

// entry point
int main() {
	bool loop = true;
	int mode = MODE_INVALID;

	while( loop ) {
		system("cls");
		cout << "faite votre choix: " << endl;
		cout << "1. PGCD " << endl;
		cout << "2. Moyenne nb Cycles (Tn) " << endl;
		cout << "3. Test Switch " << endl;
		cout << "4. Quitter " << endl;
		cout << ">";
		cin >> mode;

		switch (mode)
		{
		case PGCD:
		{
			int id = 0;
			int vals[MAX];

			while ( id < MAX )
			{
				system("cls");
				cout << "entrez l'entier positif " << id+1 << ": ";
				cin >> vals[id];
				if ( vals[id] > 0)
				{
					++id;
				}
			}

			for_each(vals, vals+id, Afficher());
			proc_PGCD(vals[0], vals[1], GetType());

			system("PAUSE");
		} break;

		case AVERAGE: 
		{
			// test Case: Tn(average nb cylce)
			int den = 0;
			while ( !den )
			{
				system("cls");
				cout << "Entrez le nombre de test : ";
				cin >> den;
				den = den>0? den: 0;
			}

			int type = GetType();

			int cumul = 0;
			for (int num=1; num<=den; ++num)
			{
				proc_PGCD(num, den, type);
				cumul += cpt;
			}

			cout << "Tn(moyen) :" << static_cast<float>(cumul)/static_cast<float>(den) << endl;
			system("PAUSE");
		} break;

		case SWITCH:
		{
			system("cls");

			// test afficher
			int id = MAX;
			int vals[MAX];
			vals[0] = 3;
			vals[1] = 5;

			cout << "entier";
			cout << dec << endl;
			for_each(vals, vals+id, Afficher()); // rappel: on passe le constructeur -> instanciation temporaire!!
			cout << "switch" << endl;
			switchValue(vals[0], vals[1]);
			for_each(vals, vals+id, Afficher());

			float fvals[MAX];
			fvals[0] = 3.0f;
			fvals[1] = 5.0f;

			cout << "virgule";
			cout << fixed << endl;
			for_each(fvals, fvals+id, Afficher());
			cout << "switch" << endl;
			switchValue(fvals[0], fvals[1]);
			for_each(fvals, fvals+id, Afficher());

			system("PAUSE");
			cout << dec;
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