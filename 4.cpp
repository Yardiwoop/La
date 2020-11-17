//Вариант 27. Завод

#include <iostream>
#include <string>
using namespace std;

class factory
{
protected:
	string name;   
	int year_found;  
public:
	factory() : name("NoName"), year_found(0)
	{}
	factory(string n, int r) : name(n), year_found(r)
	{}
	~factory()
	{}
	void output_cin()
	{
		cout << "Factory: " << name << endl;
		cout << "Year of found: " << year_found << endl;
	}
};

class workers : virtual public factory
{
protected:
	int kolvo;  

public:
	workers() : factory(), kolvo(0)
	{}
	workers(string n, int r, int t) : factory(n, r), kolvo(t)
	{}
	~workers()
	{}
	void out_cin_doc()
	{
		output_cin();
		cout << "quantity of workers: " << kolvo << endl;
	}
};

class prod : virtual public factory
{
protected:
	int kolvo_prod; 

public:
	prod() :factory(), kolvo_prod(18)
	{}
	prod(string n, int r, int a) : factory(n, r), kolvo_prod(a)
	{}
	~prod() {}
	void output_cin_fic()
	{
		output_cin();
		cout << "kolvo of production: " << kolvo_prod << endl;
	}
};

class super_workers : public workers
{
protected:
	int age;   
public:
	super_workers() : workers(), age(0)
	{}
	super_workers(string n, int r, int t, int c) : factory(n, r), workers(n, r, t), age(c)
	{}
	~super_workers() {}
	void output_cin_doc_his()
	{
		out_cin_doc();
		cout << "Average age: " << age << endl;
	}
};

class import_prod : public prod
{
protected:
	int quality;     
public:
	import_prod() : prod(), quality(0)
	{}
	import_prod(string n, int r, int a, int tr) : factory(n, r), prod(n, r, a), quality(tr)
	{}
	~import_prod()
	{}
	void output_cin_fic_dr()
	{
		output_cin_fic();
		cout << "quality " << quality << " points" << endl;
	}
};

class ceh_of_import : public super_workers, public import_prod
{
protected:
	int zp;   
public:
	ceh_of_import() : super_workers(), import_prod(), zp(0)
	{}
	ceh_of_import(string n, int r, int t, int cen, int tr, int a, int cr) : factory(n, r), super_workers(n, r, t, cen), import_prod(n, r, a, tr), zp(cr)
	{}
	~ceh_of_import() {}
	void output_his_ceh()
	{
		cout << "Factory: " << name << endl;
		cout << "year_found: " << year_found << endl;
		cout << "kolvo workers: " << kolvo << endl;
		cout << "kolvo of production: " << kolvo_prod <<"%"<< endl;
		cout << "average age of superworkers: " << age << endl;
		cout << "quality: " << quality << " point" << endl;
		cout << "zp of import ceh: " << zp << endl;
	}

};

int input_int(int min, int max);

int main()
{
	string name ;
	int age, kolvo, kolvoprod, year_found, quality, zp;
	cout << "Hello! What is the name of factory?" << endl;
	rewind(stdin);
	getline(cin, name);
	cout << "year_found?" << endl;
	year_found = input_int(1800,2020);
	cout << "kolvo of workers?" << endl;
	kolvo = input_int(0, 10000);
	cout << "age of superworkers?" << endl;
	age = input_int(18, 65);
	cout << "kolvo of production in procents?" << endl;
	kolvoprod = input_int(0, 100);
	cout << "Qyality of import production from 0 to 10?." << endl;
	quality = input_int(0, 10);
	cout << "zp of superworkers?" << endl;
	zp = input_int(500, 2000);
	system("cls");
	ceh_of_import* hd = new ceh_of_import(name, year_found, kolvo, age, quality, kolvoprod, zp);
	hd->output_his_ceh();
	delete hd;
	cout << "\nEnd of program" << endl;
	return 0;
}

int input_int(int min, int max)
{
	int i;
	bool fail = true;
	do
	{
		cin >> i;
		if (cin.fail() || i < min || i>max || cin.rdbuf()->in_avail() > 1)
			cout << "Error. Please input again." << endl;
		else
			fail = false;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		rewind(stdin);
	} while (fail);
	return i;
}


